#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,5,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<n;i++){
        arr[i]+=arr[i-1];
    }
    bool flag=false;
    for(int i=0;i<n;i++){
        if(2*arr[i]==arr[n-1]){
            flag=true;
        }
    }
    if(flag) cout<<"Yes it can be paricipated";
    else cout<<"Not possible";
    return 0;
}