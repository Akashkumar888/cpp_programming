#include<iostream>
using namespace std;
void display(int *a,int x){
    for(int i=0;i<x;i++){
        cout<<a[i]<<" ";
    }
cout<<endl;
}
void change(int *b,int y){
    b[0]=100;
}
int main(){
    int arr[]={1,2,59,3,45,56};
    int n=sizeof(arr)/4;
    // int n=sizeof(arr)/sizeof(arr[4]);
    // int n=sizeof(arr)/sizeof(arr[0]);
    display(arr,n);
    change(arr,n);
    display(arr,n);
    return 0;
}