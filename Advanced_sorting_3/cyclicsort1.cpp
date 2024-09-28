#include<iostream>
#include<vector>
using namespace std;
int main(){
int arr[]={4,2,5,1,3,6,9,7,8};
int n=sizeof(arr)/sizeof(arr[0]);
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
int i=0;
while(i<n){
    int correctIdx=arr[i]-1;
    if(correctIdx==i) i++;
    else swap(arr[correctIdx],arr[i]);
}
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
    return 0;
}