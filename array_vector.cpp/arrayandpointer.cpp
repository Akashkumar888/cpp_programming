#include<iostream>
using namespace std;
int main(){
    char arr[]={'a','e','i','o','u'};
    char *ptr=arr;
    cout<<*ptr<<endl;
    cout<<ptr[0]<<endl;
    cout<<ptr<<endl;
    cout<<&arr[0]<<endl;
    char *ptr2=&arr[0];
    cout<<ptr2<<endl;
    int n=sizeof(arr)/1;
    // int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
    cout<<ptr2[i]<<" ";
    }
    return 0;
}