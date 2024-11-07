#include<iostream>
using namespace std;
int main()
{
    int arr[5]={1,2,3,4,5};
    int *ptr=arr;
    for(int i=0;i<5;i++)
    cout<<ptr[i]<<" ";

    cout<<endl;

    for(int i=0;i<5;i++)
    cout<<i[ptr]<<" ";
    cout<<endl;
    
    for(int i=0;i<5;i++)
    cout<<*(ptr+i)<<" ";

 // arithmetic operations
    cout<<endl;
    
    for(int i=0;i<5;i++){
    cout<<*ptr<<" ";
    ptr++;
    }
    cout<<endl;
    ptr--;
    ptr--;
    cout<<*ptr<<" ";
return 0;
}