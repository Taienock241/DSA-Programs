#include <iostream>
using namespace std;

struct Node{
    Node *prev;
    int data;
    Node *next;
    
    Node(int value):data(value),prev(NULL), next(NULL){}
};

Node *InsertBeg(Node *head, int value){
    Node *newNode = new Node(value);
    
    newNode->next = head;
    newNode->prev= NULL;
    if(head !=NULL){
        head->prev= newNode;
    }
    head = newNode;
    return head;
}

void fTraverse(Node *head){
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


void bTraverse(Node *tail){
    if(tail==NULL){
        cout<<"list is empty";
    }
    Node *current = tail;
    while(current!=NULL){
        cout<<current->data<<"->";
        current = current->prev;
    }
    cout<<"NULL"<<endl;
}
Node *End(Node *head, int value){
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

//insert at any position
Node *AnyPos(Node *head, int value, int pos){
    if(pos ==0){
        return InsertBeg(head, value);
    }
    Node *newNode = new Node(value);
    Node *current = head;

    for(int i = 0; i<pos - 1 && current != NULL;i++){
        current= current->next;
    }
    newNode->next=current->next;
    newNode->prev= current;
    if(current->next != NULL){
        current->next->prev = newNode;

    }
    current->next=newNode;
    return head;

}


int main(){
    Node *head = new Node(1200);

    head = InsertBeg(head,1258);
    head = InsertBeg(head,1257);
    head = InsertBeg(head,1256);
    head = InsertBeg(head,1255);
    head = InsertBeg(head,1254);
    head = InsertBeg(head,1253);
    head = InsertBeg(head,1252);
    
    head = End(head,12085);
    head =AnyPos(head,1500,0);

    
    fTraverse(head);
    bTraverse(head);
    return 0;
}















