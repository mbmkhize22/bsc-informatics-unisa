#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* Next;
};

void printList(Node*n) {
    while(n!=NULL) {
        cout << n->value << endl;
        n = n->Next;
    }
}

// Inserting pointer to a pointer(**)
void insertAtTheFront(Node**head, int newValue) {
    //Steps
    //1. prepare new node
    Node* newNode = new Node();
    newNode->value = newValue;

    //2. Put it in front of the current head
    newNode->Next = *head;

    //3. Move head of the list to point to the new node
    *head = newNode;
}

void insertAtTheEnd(Node**head, int newValue) {
    // 1. prepare a new node
    Node* newNode = new Node();
    newNode->value = newValue;
    newNode->Next = NULL;

    //2. If linked list is empty, newNode will be a head node
    if(*head == NULL) {
        *head = newNode;
        return;
    }

    //3. Find the last node
    Node* last = *head;
    while(last->Next != NULL) {
        last = last->Next;
    }

    //4. Insert newNode after last node(at the end)
    last->Next = newNode;
}

void insertAfter(Node*previous, int newValue) {
    //1. Check if previous node is NULL
    if(previous == NULL) {
        cout << "Previous can not be NULL";
        return;
    }

    //2. Prepare a newNode
    Node* newNode = new Node();
    newNode->value = newValue;

    //3. Inaert newNode after previous
    newNode->Next = previous->Next;
    previous->Next = newNode;
}

int main()
{
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->value = 1;
    head->Next = second;

    second->value = 2;
    second->Next = third;

    third->value = 3;
    third->Next = NULL;

    insertAtTheFront(&head, -1);
    insertAtTheEnd(&head, 4);
    insertAtTheEnd(&head, 5);
    insertAfter(head, 1000);
    insertAfter(second, 2000);
    printList(head);

    cout << "Hello world!" << endl;
    return 0;
}
