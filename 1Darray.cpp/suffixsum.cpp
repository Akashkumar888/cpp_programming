#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/4;
    vector<long long>prefixsum(n);
    prefixsum[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        prefixsum[i]=prefixsum[i+1]+arr[i];
    }
    for(int i=0;i<n;i++){
       cout<<prefixsum[i]<<" ";
    }
    return 0;
}