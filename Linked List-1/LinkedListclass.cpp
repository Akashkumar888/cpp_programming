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
void insertatEND(int val){
Node * temp=new Node(val);
if(size==0) head=tail=temp;
else{
    tail->next=temp;
    tail=temp;
}
size++;
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
void insertat_index(int idx,int val){
    if(idx<0 || idx>size) cout<<"Invalid index";
   else if(idx==0){
     insertatbeg(val);
     return ;
    }    
    else if(idx==size){
        insertatEND(val);
        return;
    }
    else{
       Node *t=new Node(val);
       Node *temp=head;
       for(int i=1;i<=idx-1;i++){
        temp=temp->next;
       }
       t->next=temp->next;
       temp->next=t;
       size++;
    }
}
void getvalue_at_index(int idx){
    if(idx<0 || idx>size) cout<<"Invalid index";
    if(idx==0) cout<< head->val;
    if(idx==size-1) cout<< tail->val;
    else{
    Node*temp=head;
       for(int i=1;i<=idx;i++){
        temp=temp->next;
       }
       cout<<temp->val;
       size++;
    }
    cout<<endl;
}
void delete_at_head(){
    if(size==0) cout<<"list is empty";
    if(size>=1){
        head=head->next;
        size--;
    }
}
void delete_at_tail(){
    if(size==0) cout<<"list is empty";
    if(size>=1){
        Node* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
            temp->next=NULL;
            tail=temp;
        size--;
    }
}
void delete_at_index(int idx){
    if(size==0) cout<<"List is empty";
    else if(idx<0 || idx>=size) cout<<"Invalid index";
    else if(idx==0) delete_at_head();
    else if(idx==size-1) delete_at_tail();
    else {
     Node*temp=head;
     for(int i=1;i<=idx-1;i++){
        temp=temp->next;
     }
     temp->next=temp->next->next;
     size--;
    }
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
ll.insertatEND(57);
ll.display();
ll.insertatEND(34);
ll.display();
ll.insertatEND(78);
ll.insertatEND(94);
ll.display();
cout<<ll.size<<endl;
ll.insertatbeg(55);
ll.display();
ll.insertatbeg(67);
ll.display();
ll.insertatbeg(89);
ll.insertatbeg(23);
ll.display();
cout<<ll.size<<endl;
ll.insertat_index(5,897);
ll.display();
ll.getvalue_at_index(6);
ll.delete_at_head();
ll.display();
ll.delete_at_tail();
ll.display();
ll.delete_at_index(4);
ll.display();
    return 0;
}