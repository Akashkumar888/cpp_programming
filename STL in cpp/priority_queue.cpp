#include<iostream>
#include<queue>
using namespace std;
int main(){
    // max heap
    priority_queue<int>maxi;
// mini heap
priority_queue<int,vector<int>,greater<int>>mini;
maxi.push(56);
maxi.push(45);
maxi.push(48);
maxi.push(67);
maxi.push(89);
cout<<"Size is :"<<maxi.size()<<endl;
int n=maxi.size();
for(int i=0;i<n;i++){
    cout<<maxi.top()<<"  ";
    maxi.pop();
}
cout<<endl;
    return 0;
}