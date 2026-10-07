#include<iostream>
using namespace std;

struct node{
    node *prev;
    int data;
    node *next;
};

node *addtoEmpty(node *head, int data){
    node *temp = new node();
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

int main(){
    node *head = new node();
    head->prev = NULL;
    head->data = 45;
    head->next = NULL;
    cout<<head->data<<endl;


    int data;
    cout<<"enter data: ";
    cin>>data;

    head = addtoEmpty(head , data);

    cout<<head->data;
    

    return 0;
}