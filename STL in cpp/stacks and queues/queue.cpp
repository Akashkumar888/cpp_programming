#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<int>q;
    q.push(2);
    q.push(4);
    q.push(5);
    q.push(7);
    q.push(9);
    int n=q.size();
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}