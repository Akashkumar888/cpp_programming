

#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void print(queue<int>&q){
    int n=q.size();
    for(int i=1;i<=n;i++){
        int x=q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
    cout<<endl;
}


void remove(queue<int>&q){
    int n=q.size();
    for(int i=0;i<n;i++){
        if(i%2!=0){
            int x=q.front();
             q.push(x);
        }
            q.pop();
    }
}
int main(){
queue<int>q;
q.push(1);
q.push(2);
q.push(3);
q.push(4);
q.push(5);
q.push(6);
q.push(7);
q.push(8);
q.push(9);
print(q);
remove(q);
print(q);
    return 0;
}
