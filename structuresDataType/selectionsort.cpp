// Online C++ compiler (editor)
// Write and run C++ online using this editor.

#include <iostream>
using namespace std;
void selectionsort(int arr[], int n){
    for(int i = (n-1);i>0;i--){
      int pos_greatest = 0;
        for(int j=1;j<=i;j++){
            if(arr[j]>arr[pos_greatest])
              pos_greatest = j;
        }
swap(arr[i],arr[pos_greatest]);   
    }
}


void  selectionsort2(int arr[], int n){
for(int i= 0;i<n;i++ ){
    int minIndex= i;
     for(int j=i+1;j<n;j++){
         if(arr[j]<arr[minIndex])
             minIndex = j;
     }
    swap(arr[i],arr[minIndex]);
}
   
}




int main() {
int arr[] ={12,45,85,41,25,10,25,13};
int n = sizeof(arr)/sizeof(arr[0]);
selectionsort(arr,n);

    cout<<"sorted array: ";
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }


    


    


    
  
    return 0;
}