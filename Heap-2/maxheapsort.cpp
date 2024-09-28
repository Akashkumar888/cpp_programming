

#include<iostream>
#include<queue>
using namespace std;
int main(){
    int arr[]={10,1,2,20,5,8,6,11,16,25,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    priority_queue<int>pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    int i=0;
    while(!pq.empty()){
      int val=pq.top();
      pq.pop();
      arr[i]=val;
      i++;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}