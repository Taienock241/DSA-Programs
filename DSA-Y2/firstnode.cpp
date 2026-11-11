#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *link;  //self referential structure--> points to a structure of the same type
};

int main(int argc, char const *argv[])
{
    struct node*head;
    head = NULL;
    head =(struct node *)malloc(sizeof(struct node));
    head->data=78;
    head->data=63;
    head->link=NULL;
    cout<<head->data<<"->"<<" NULL";


    return 0;
}
