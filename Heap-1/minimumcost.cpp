
#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int,vector<int>,greater<int>>pq;
    // int arr[]={2,7,4,1,8};
    int arr[]={6,5,3,2,8,10,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    int micost=0;
    while(pq.size()>1){
        int x1=pq.top();
        pq.pop();
        int y1=pq.top();
        pq.pop();
        pq.push(x1+y1);
       micost += x1+y1;
    }
    cout<<micost<<endl;
    return 0;
}
