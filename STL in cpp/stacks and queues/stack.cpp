#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int>s;
    s.push(5);
    s.push(7);
    s.push(8);
    s.push(3);
    s.push(1);
    int n=s.size();
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}