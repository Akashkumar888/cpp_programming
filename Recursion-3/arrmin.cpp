#include<iostream>
#include<climits>
using namespace std;
void printmin(int arr[],int n,int idx,int min){
    if(idx==n){
        cout<<min;
        return;
    }
    if(min>arr[idx])min=arr[idx];
    printmin(arr,n,idx+1,min);
}
int main(){
    int arr[]={10,60,90,23,7,57,234,904,2356,39,4578,92};
    int n=sizeof(arr)/sizeof(arr[0]);
    printmin(arr,n,0,INT_MAX);
    return 0;
}