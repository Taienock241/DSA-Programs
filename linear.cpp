#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int arr[]={98,58,52,60,45,75};

  int arr2[] ={45,2,8,7,9,10,11,12,13,14,15,16,17,18,19,20};

  

  int target = 75;

int n = sizeof(arr)/sizeof(arr[0]);
 cout<<"size of array :: "<<n<<endl;
for(int i=0;i<n;i++){
    if(arr[i]==target){
        cout<<"target found at index "<<i<<endl;
        break;
    }
  }

sort(arr,arr+n);
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
    int low = 0;
    int high = n-1;
    while(low<=high){   // verifying if the target is present in the array or not
        int mid = (low+high)/2;
        if(arr[mid]==target){
            cout<<"target found at index "<<mid<<endl;
            break;
        }else if(arr[mid]<target){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }


return 0;
}


 