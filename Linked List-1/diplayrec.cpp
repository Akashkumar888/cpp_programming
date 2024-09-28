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
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
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
void displayrec(Node* head){
    if(head==NULL) return;
    cout<<head->val<<" ";
    displayrec(head->next);
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
cout<<size(a);
cout<<endl;
displayrec(a);
    return 0;
}