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
void display(Node* head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}
int size(Node* head){
    Node *temp=head;
    int n=0;
    while(temp!=NULL){
        temp=temp->next;
        n++;
    }
    return n;
}
void insertatEND(Node *temp,int val){
    Node *t=new Node(val);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=t;
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
display(a);
cout<<endl;
cout<<size(a)<<endl;
insertatEND(a,12);
display(a);
cout<<endl;
cout<<size(a);
    return 0;
}