
#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int>dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    dq.pop_back();

    dq.push_front(40);
    dq.push_front(50);

    dq.pop_front();

    while(dq.size()!=0){
        cout<<dq.front()<<" ";
        dq.pop_front();
    }
    
    // while(dq.size()!=0){
    //     cout<<dq.back()<<" ";
    //     dq.pop_back();
    // }
    
    return 0;
}