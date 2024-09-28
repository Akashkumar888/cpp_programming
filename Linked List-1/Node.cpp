#include<iostream>
using namespace std;
class Node{
public:
int val;
Node* next;
Node(int val){
    this->val=val;
    this->next=NULL;
}
};
int main(){
    Node a(10);
    Node b(40);
    Node c(70);
    Node d(90);
    return 0;
}