//59415983
#include <iostream>
#include <fstream>
#include <string>
#include <regex>


using namespace std;

struct Node {
    string url;
    Node* next;
};

class Stack {
public:
    Node* top;

    Stack() : top(nullptr) {}

    void push(string url) {
        Node* newNode = new Node{url, top};
        top = newNode;
    }

    string pop() {
        if (isEmpty()) return "Stack is empty";
        Node* temp = top;
        string url = top->url;
        top = top->next;
        delete temp;
        return url;
    }

    string peek() {
        return (top == nullptr) ? "Stack top is empty" : top->url;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

bool validateURL(const string& url);


void displayMenu() {
    cout << "MENU\n1. New URL\n2. Navigate back\n3. Navigate forward\n4. Exit" << endl;
}

int program(Stack& backStack, Stack& forwardStack) {

    int input;
    string url, currentURL = backStack.peek();

    while (true) {
        displayMenu();
        cin >> input;
        switch (input) {
            case 1:
                cout << "Enter URL: ";
                cin >> url;
                if (validateURL(url)) {
                    backStack.push(url);
                    currentURL = url;
                    forwardStack = Stack();  // Clear forward history
                } else {
                    cout << "Invalid URL format.\n";
                }
                break;
            case 2:
                if (!backStack.isEmpty()) {
                    forwardStack.push(currentURL);
                    cout << currentURL << endl;
                    currentURL = backStack.pop();
                } else {
                    cout << "No more history\n";
                }
                break;
            case 3:
                if (!forwardStack.isEmpty()) {
                    backStack.push(currentURL);
                    cout << currentURL << endl;
                    currentURL = forwardStack.pop();
                } else {
                    cout << "No forward history\n";
                }
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

void loadInitialURLs(Stack& backStack) {
    ifstream file("C:\\Data\\BrowserHistory.txt");
    string url;
    while (getline(file, url)) {
        backStack.push(url);
    }
    file.close();
}

bool validateURL(const string& url) {
    regex pattern("www\\..+\\..+");
    return regex_match(url, pattern);
}

int main()
{
    Stack backStack, forwardStack;
    loadInitialURLs(backStack);
    program(backStack, forwardStack);
    return 0;
}
