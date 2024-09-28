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
void displayrec(Node* head){
    if(head==NULL) return;
    cout<<head->val<<" ";
    displayrec(head->next);
}
void reversedisplay(Node* head){
    if(head==NULL) return;
   reversedisplay(head->next);
    cout<<head->val<<" ";
}
int main(){
Node* a=new Node(20);
Node* b=new Node(60);
Node* c=new Node(80);
Node* d=new Node(50);
Node* e=new Node(45);
a->next=b;
b->next=c;
c->next=d;
d->next=e;
displayrec(a);
cout<<endl;
reversedisplay(a);
    return 0;
}