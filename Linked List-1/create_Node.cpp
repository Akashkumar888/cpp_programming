#include<iostream>
using namespace std;
class Node{
public:
int val;
Node* next;
};
int main(){
    Node a;
    a.val=10;
    Node b;
    b.val=20;
    Node c;
    c.val=70;
    Node d;
    d.val=40;
    a.next=&b;
    b.next=&c;
    c.next=&d;
    d.next=NULL;
    return 0;
}