#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[]={5,1,8,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v(arr,arr+n);
    int count=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j] && i<j){
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}