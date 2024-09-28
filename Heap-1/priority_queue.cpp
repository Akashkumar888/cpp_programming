
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
cout<<pq.top()<<endl;
pq.pop();
cout<<pq.top()<<endl;
pq.push(29);
cout<<pq.top()<<endl;
    return 0;
}
