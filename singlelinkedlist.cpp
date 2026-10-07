#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    
    Node(int value):data(value),next(NULL){}
};

Node *insertAtFront(Node *head, int value){
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    return head;
    
}

Node *atEnd(Node *head, int value){
    Node *newNode = new Node(value);
    
    if(head==NULL){
        return newNode;
    }
    
    Node *current = head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
    return head;
}

Node *anyPos(Node *head, int value, int pos){
    if(pos == 0){
        return insertAtFront(head,value);
    }
    Node *newNode = new Node(value);
    Node *current = head;
    
    for(int i=0; i<pos-1 && current!= NULL;i++){
        current = current->next;
    }
    
    if(current == NULL){
        cout<<"Error";
        delete newNode;
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

void traverse(Node *head){
    Node *current = head;
    
    while(current != NULL){
        cout<<current->data<<"->";
        current = current->next;
    }
    cout<<"NULL"<<endl;
}
//delete at the end
Node *atBeg(Node *head){
    Node *temp = head;
    head = head->next;
    delete temp;
    cout<<"this is what was deleted "<<temp->data<<endl;
    return head;

}

//at  the end
Node *atTail(Node *head){
    if(head==NULL){
        cout<<"list is empty";
    }
    Node *current = head;
    while(current->next!=NULL){
      current= current->next;
    }
    delete current;
    cout<<"Tail data deleted : "<<current->data<< " "<< current->next<<endl;
    current->next=NULL;
    return head;

}
//delete by value
Node *byValue(Node *head, int value){
    Node *current = head;

    while(current->next!=NULL && current->next->data!=value){
        current = current->next;
    }
    cout<<current->data;
    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
    cout<< "data deleted: " <<temp->data<<endl;
    return head;

}


int main(){
    Node*head = new Node(12);
    
    
head = insertAtFront(head,1400);
head = insertAtFront(head,1401);
head = insertAtFront(head,1402);
head = insertAtFront(head,1403);



/*head = atEnd(head, 1258);

head = anyPos(head, 1454, 0);
head = anyPos(head, 5454, 5);*/

head = atTail(head);
head = atBeg(head);
head = byValue(head, 1400);

traverse(head);
    return 0;
    
}