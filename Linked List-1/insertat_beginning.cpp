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
class Linkedlist{
    public:
int size;
Node* head;
Node* tail;
Linkedlist(){
    head=tail=NULL;
    size=0;
}
void insertatbeg(int val){
Node *temp=new Node(val);
if(size==0) head=tail=temp;
else{
    temp->next=head;
    head=temp;
}
size++;
}
void display(){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
};
int main(){
Linkedlist ll ; 
ll.insertatbeg(57);
ll.display();
ll.insertatbeg(34);
ll.display();
ll.insertatbeg(78);
ll.insertatbeg(94);
ll.display();
cout<<ll.size<<endl;
    return 0;
}