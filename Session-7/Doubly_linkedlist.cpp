#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;
};

Node* createNode(int data) 
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void insertAtBeginning(Node*& head, int data) 
{
    Node* newNode = createNode(data);
    if (head == nullptr) 
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtEnd(Node*& head, int data) 
{
    Node* newNode = createNode(data);
    if (head == nullptr) 
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(Node*& head, int data, int pos) 
{
    if(pos == 1) 
    {
        insertAtBeginning(head, data);
        return;
    }
    Node* newNode = createNode(data);
    Node* temp = head;
    for(int i = 1; i < pos-1 && temp != nullptr; i++)
    {   
         temp = temp->next;
    }
    if(temp == nullptr) 
    {
        return;
    }
    newNode->next = temp->next;
    if(temp->next != nullptr)
    {
         temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteBeginning(Node*& head) 
{
    if(head == nullptr) 
    {
        return;
    }
    Node* temp = head;
    head = head->next;
    if(head != nullptr) 
    {
        head->prev = nullptr;
    }
    delete temp;
}

void deleteEnd(Node*& head) 
{
    if(head == nullptr) 
    {
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    if(temp->prev != nullptr)
    {
        temp->prev->next = nullptr;
    }
    else
    {
        head = nullptr;
    }
    delete temp;
}

void deletePosition(Node*& head, int pos)
{
    if(head == nullptr)
    {
        return;
    }

    if(pos == 1) 
    {
        deleteBeginning(head);
        return;
    }
    Node* temp = head;
    for(int i = 1; i < pos && temp != nullptr; i++)
    {
        temp = temp->next;
    }
    if(temp == nullptr) 
    {
        return;
    }
    if(temp->prev != nullptr)
    {
        temp->prev->next = temp->next;
    }
    if(temp->next != nullptr) 
    {
        temp->next->prev = temp->prev;
    }
    delete temp;
}

void printForward(Node* head) 
{
    Node* temp = head;
    while(temp != nullptr) 
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printBackward(Node* head) 
{
    if(head == nullptr) 
    {
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    while(temp != nullptr) 
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() 
{
    Node* head = nullptr;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtBeginning(head, 5);
    insertAtPosition(head, 15, 3);

    printForward(head);
    printBackward(head);

    deleteBeginning(head);
    deleteEnd(head);
    deletePosition(head, 2);

    printForward(head);
    printBackward(head);

    return 0;
}
