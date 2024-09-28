#include<iostream>
using namespace std;
int main(){
    int arr[]={1,1,3,6,2,3,2,6,7,9,8,7,4,8,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int res=0;
    for(int i=0;i<n;i++){
        res=res^arr[i];
    }
    cout<<res;
    return 0;
}