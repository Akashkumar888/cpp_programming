#include<iostream>
#include<climits>
using namespace std;
void printmax(int arr[],int n,int idx,int max){
    if(idx==n){
        cout<<max;
        return;
    }
    if(max<arr[idx])max=arr[idx];
    printmax(arr,n,idx+1,max);
}
int main(){
    int arr[]={10,60,90,23,12,57,234,904,2356,39,45,89,47};
    int n=sizeof(arr)/sizeof(arr[0]);
    printmax(arr,n,0,INT_MIN);
    return 0;
}