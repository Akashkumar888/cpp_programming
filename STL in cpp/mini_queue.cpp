#include<iostream>
#include<queue>
using namespace std;
int main(){
// mini heap
priority_queue<int,vector<int>,greater<int>>mini;
mini.push(56);
mini.push(45);
mini.push(48);
mini.push(67);
mini.push(89);
cout<<"Size is :"<<mini.size()<<endl;
int n=mini.size();
for(int i=0;i<n;i++){
    cout<<mini.top()<<"  ";
    mini.pop();
}
cout<<endl;
cout<<"Khali hai kya bhai :"<<mini.empty()<<endl;
    return 0;
}