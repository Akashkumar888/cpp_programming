#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<string>q;
q.push("Akash");
q.push("Kumar");
q.push("Nitish");
q.push("surya");
q.push("Aditya");
cout<<"size of queue :"<<q.size()<<endl;
cout<<"first element :"<<q.front()<<endl;
q.pop();
cout<<"first element :"<<q.front()<<endl;
cout<<"last element :"<<q.back()<<endl;
cout<<"size of queue :"<<q.size()<<endl;
    return 0;
}