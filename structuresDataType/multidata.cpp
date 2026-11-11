#include <iostream>
#include <string>
using namespace std;

// A struct groups related data and functions into one user-defined type.
struct Node
{
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};
// function to create a linked list from an array of integers

void createLinkedList(Node*&head, int data)
{
    Node* newNode = new Node(data);
if (head == nullptr)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    else
    {
       newNode->next = head;
        head = newNode;
    }

}



Node* insertAtEnd(Node* head, int data)
{
    Node* newNode = new Node(data);
    if (head == nullptr)
    {
        return newNode;
    }
    else
    {
        Node* current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = nullptr;
    }
    return head;
}


void printList(Node* head)
{
    Node* temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* deleteBeg(Node* head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}


int main()
{
    Node* head = new Node(10);
   createLinkedList(head, 20);
   createLinkedList(head, 30);
   createLinkedList(head, 40);


   head = insertAtEnd(head, 50);
   head = insertAtEnd(head, 60);

   head = deleteBeg(head);
   printList(head);



    return 0;
}