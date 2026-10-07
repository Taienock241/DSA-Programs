
/*//binary search in c++
#include <iostream>
using namespace std;
int binarySearch(int arr[], int n , int target){
    int low = 0;
    int high = n-1;
    
    while(low<=high){
        int mid =(low+high)/2;
        if(arr[mid]==target){
            return mid;
        }else if(arr[mid]<target){
            low=mid+1;
        }else{
            high = mid -1;
        }
    }
   return -1; 
}

int main() {
	// your code goes here
	int arr[] = {17,20,28,34,89,100,150,156,160};
	int n= sizeof(arr)/sizeof(arr[0]);
	
	int target = 34;
	int result = binarySearch(arr,n,target);
	if(result!= -1){
	    cout<<"target in index "<<result<<endl;
	}else{
	    cout<<"target not fouund";
	}
	
	float num = 12.5;
	int num1 = (int)num;
	cout<<num1;
	
	return 0;

}

//queue implementation in c++ by arrays
#include <iostream>
using namespace std;
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data){
    
    if(rear == MAX-1){
        cout<<"queue overflow";
    }else{
        if(front ==-1)front=0;
        rear++;
        queue[rear]=data;
        cout<<queue[rear]<<" inserted"<<endl;
        
    }
}

void display(){
    if(front==-1 && rear==-10){
        cout<<"queue empty";
    }else{
        for(int i = front; i<=rear;i++){
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
}

  void dequeue(){
      if(front==-1){
          cout<<"queue empty";
      }else{
          cout<<queue[front]<<" deleted"<<endl;
          front++;
      }
  }

int main() {
	enqueue(25 );
	enqueue( 58);
	enqueue( 12);
	enqueue( 22);
	enqueue( 52);
display();
dequeue();
display();
	
	return 0;

}
//stack implementation in c++ by linked list

#include <iostream>
using namespace std;

struct stack{
    int data;
    stack *next;
    
    stack(int value):data(value),next(0){}
};

stack *top = 0;

void push(int data){
    stack *newNode = new stack(data);
    if(top==0){
        top  = newNode;
    }else{
        newNode->next = top;
        top = newNode;
        cout<<data<< " inserted"<<endl;
    }
}

void display(){
    if(top==0){
        cout<<"stack empty";
    }else{
        stack *temp = top;
        cout<<"data in stack :: ";
        while(temp!=0){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}

void pop(){
    if(top==0){
        cout<<"stack underflow";
    }else{
        stack *temp = top;
        top = top->next;
        cout<<"deleted :: "<<temp->data<<endl;
        delete temp;
    }
}

int main() {
push(12 );
push( 15);
push( 16);
display();
pop();
display();
return 0;

}*/

//queue implementation in c++ by linked list
#include <iostream>
using namespace std;

struct QueueNode{
    int data;
    QueueNode *next;
    
    QueueNode(int value):data(value), next(0){}
    
};
QueueNode *front = 0;
QueueNode *rear = 0;

void insertatBeg(int data){  //enqueue operation
    QueueNode *newNode= new QueueNode(data);
    
    if(rear==0){
        front=rear=newNode;
    }else{
        rear->next=newNode;
        rear= newNode;
        cout<<data<<" inserted and else part executed"<<endl;
    }
}

void display(){
    
    if(rear==0 && front == 0){
        cout<<"queue is empty";
    }else{
        QueueNode *temp = front;
        cout<<"queue items :: ";
        while(temp != 0){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}

void dequeue(){
    if(front==0){
        cout<<" queue underflow";
    }else{
        QueueNode *temp = front;
        front = front->next;
        cout<<"data deleted :: "<<temp->data<<endl;
        delete temp;
        
        if(front==0){
            rear=0;
        }
    }
}

int main() {
    insertatBeg(10 );
    insertatBeg( 56);
    insertatBeg(12 );
    insertatBeg( 23);
     display();
     dequeue();
     dequeue();
    display();
    return 0;

}


//stack implementation in c++ by arrays

#include <bits/stdc++.h>
using namespace std;
#define MAX 5
int arr[MAX];
int top = -1;

void insertData(int data){  //push operation
    if(top==MAX-1){
        cout<<data<<" :stack overflow"<<endl;
    }else{
    top++;
    arr[top]=data;
    cout<<data<<" inserted "<<endl;
    }
}
void displayStack(){
    for(int i=0;i<=top;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void deleteData(){  //pop operation
    if(top==-1){
        cout<<"stack empty || underflow";
    }else{
    cout<<arr[top]<<" deleted"<<" :: ";
    top--;
    cout<<"top element now= "<<arr[top]<<endl;
        
    }
    
}

int stackDemo() {
insertData(23 );
insertData( 12);
insertData( 15);
insertData(55 );
insertData(89 );
insertData( 45);

displayStack();
deleteData();
displayStack();


return 0;

}
