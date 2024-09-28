#include<iostream>
#include<climits>
using namespace std;
int arrInmax(int arr[],int n,int idx){
    if(idx==n) return INT_MIN;
    return max(arr[idx],arrInmax(arr,n,idx+1));
}
int main(){
    int arr[]={10,60,90,23,7,57,234,904,2356,39,45,78,92};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<arrInmax(arr,n,0);
    return 0;
}