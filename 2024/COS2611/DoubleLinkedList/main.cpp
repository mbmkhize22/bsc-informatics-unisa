// https://www.youtube.com/watch?v=-StYr9wILqo

#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* previous;
};

void printForward(Node*head) {
    Node* traversor = head;
    while(traversor != nullptr) {
        cout << traversor->value << endl;
        traversor = traversor->next;
    }
}

void printBackwards(Node*tail) {
    Node* traversor = tail;
    while(traversor != nullptr) {
        cout << traversor->value << endl;
        traversor = traversor->previous;
    }
}

int main()
{
    Node* head; // first element
    Node* tail; // last element

    //Add fist node
    Node* node = new Node();
    node->value = 4;
    node->next = nullptr;
    node->previous = nullptr;
    head = node;
    tail = node;

    //Add 2nd node
    node = new Node();
    node->value = 5;
    node->next = nullptr;
    node->previous = tail;
    tail->next = node;
    tail = node;

    //Add 3rd node
    node = new Node();
    node->value = 6;
    node->next = nullptr;
    node->previous = tail;
    tail->next = node;
    tail = node;

    //Add 4th node
    node = new Node();
    node->value = 7;
    node->next = nullptr;
    node->previous = tail;
    tail->next = node;
    tail = node;

    printForward(head);
    printBackwards(tail);

    cout << "Hello world!" << endl;
    return 0;
}
