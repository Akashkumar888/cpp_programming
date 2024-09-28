

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
int arr[]={6,5,3,2,8,10,9};
int k=3;
int n=sizeof(arr)/sizeof(arr[0]);
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
priority_queue<int,vector<int>,greater<int>>pq;
int idx=0;
for(int i=0;i<n;i++){
    pq.push(arr[i]);
    if(pq.size()>k){
        arr[idx++]=pq.top();
        pq.pop();
    }
} 
while(!pq.empty()){
     arr[idx++]=pq.top();
     pq.pop();
}
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
    return 0;
}
