

#include<iostream>
#include<queue>
using namespace std;
int main(){
priority_queue<int>pq; // by default max heap
pq.push(3);
pq.push(1);
pq.push(5);
pq.push(7);
pq.push(10);
// while(pq.size()!=0){
//     cout<<pq.top()<<" ";
//     pq.pop();
// }
// cout<<endl;
while(!pq.empty()){
    cout<<pq.top()<<" ";
    pq.pop();
}
    return 0;
}
