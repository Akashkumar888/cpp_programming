#include<iostream>
using namespace std;
int main(){
    // int n;
    // cout<<"Enter binary: ";
    // cin>>n;
    int arr[100];
    int sum=0,x=1;
    for(int i=6;i>=0;i--){
        sum=sum+arr[i]*x;
        x=x*2;
    }
    cout<<x;
    return 0;
}