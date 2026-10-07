#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
void insrtAtBeginning(Node*&head, int value){
    Node*newNode =new Node(); //memory allocation here ---defines a node
    newNode->data=value;
    if(head==NULL){
        newNode->next=NULL;
        head=newNode;
    }else{
        newNode->next=head;
        head = newNode;
    }
}

void printList(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

}

int main()
{
     Node*head=NULL;
     insrtAtBeginning(head,30);
     insrtAtBeginning(head,78);
     insrtAtBeginning(head,38);
     insrtAtBeginning(head,1000);
  
     printList(head);
    return 0;
}
