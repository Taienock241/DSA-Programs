#include <iostream>
using namespace std;

int main(){

    int count  = 4;
    for (int i = 0; i < count; i++)
    {
        cout<<"outer loop "<<i<<endl;
        for (int j = 0; j < i; j++)
       {
           cout<<"inner loop: "<<j<<endl;
        }
        
    }
 return 0;   
}