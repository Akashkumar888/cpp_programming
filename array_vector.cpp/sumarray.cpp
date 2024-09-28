#include<iostream>
using namespace std;
void display(int a[],int x){
    int sum=0;
    for(int i=0;i<x;i++){
        sum+=a[i];
    }
cout<<sum;
}
int main(){
    int arr[]={1,2,59,3,45,56};
    int n=sizeof(arr)/4;
    // int n=sizeof(arr)/sizeof(arr[4]);
    // int n=sizeof(arr)/sizeof(arr[0]);
    display(arr,n);
    return 0;
}