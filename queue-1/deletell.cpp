#include<iostream>
using namespace std;
class Node{
public:
int val;
Node*next;
Node(int val){
    this->val=val;
    this->next=NULL;
}

};
int main(){
Node*a=new Node(10);
Node*b=new Node(20);
Node*c=new Node(30);
a->next=b;
b->next=c;
Node*h=a;
delete(h);
cout<<a->val<<endl;
    return 0;
}