#include<iostream>
using namespace std;

struct Node{
    Node *prev;
    int data;
    Node *next;

    Node(int value):data(value),prev(NULL), next(NULL){}
};
Node * isrtBeg(Node *head, int value){
    Node *newNode = new Node(value);

    newNode->next = head;
    newNode->prev= NULL;
    if(head !=NULL){
        head->prev= newNode;
    }
    head = newNode;
    return head;
}

Node*isertEnd(Node *head, int value){
    Node *newNode = new Node(value);

    newNode->next=NULL;
    if(head==NULL){
        newNode->prev=NULL;
        return newNode;
    }

    Node *current = head;
    while(current->next !=NULL){
         current = current->next;
    }
    current->next = newNode;
    newNode->prev= current;
    return head;
}

Node* deleteBeg(Node *head){
    if(head==NULL){
        cout<<"list is empty";
        return head;
    }
    Node *temp = head;
    head = head->next;
    if(head!=NULL){
        head->prev=NULL;
    }
    delete temp;
    return head;
}
Node* deleteEnd(Node *head){
    if(head==NULL){
        cout<<"list is empty";
        return head;
    }
    Node *current = head;
    while(current->next!=NULL){
        current = current->next;
    }
    if(current->prev!=NULL){
        current->prev->next=NULL;
    }else{
        head=NULL;
    }
    delete current;
    return head;
}

Node* fTraverse(Node *head){
    if(head==NULL){
        cout<<"list is empty";
    }
    Node *current = head;
    while(current!=NULL){
        cout<<current->data<<"->";
        current = current->next;
    }
    cout<<"NULL"<<endl;
}


int main(){
    Node *head = new Node(1200);

    head = isrtBeg(head,1258);
    head = isrtBeg(head,1257);
    head = isrtBeg(head,1256);
    head = isrtBeg(head,1255);
    head = isrtBeg(head,1254);
    head = isrtBeg(head,1253);
    head = isrtBeg(head,1252);

    head = fTraverse(head);

    return 0;
}