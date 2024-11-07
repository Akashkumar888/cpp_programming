#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<string>q;
    q.push("Akash");
    q.push("Kumar");
    q.push("Qwerty");
    q.push("Asdfg");
    q.push("xcvb");
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}