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
    int size=0;
    head=tail=NULL;
}
void insert_at_end(int val){
    Node*temp=new Node(val);
    if(size==0)head=tail=temp;
    else{
            tail->next=temp;
            tail=temp;
    }
    size++;
}
void insert_at_beg(int val){
        Node*temp=new Node(val);
    if(size==0) head=tail=temp;
    else{
        temp->next=head;
        head=temp;
    }
    size++;
}
void insert_at_index(int idx,int val){
    if(idx<0 || size<idx) cout<<"Invalid index";
    else if(idx==0){
    insert_at_beg(val);
    return;
    }
        
    else if(idx==size) {
    insert_at_end(val);
return;
    }
    else{
        Node* t=new Node(val);
        Node* temp=head;
        for(int i=1;i<=idx-1;i++){
        temp=temp->next;
        }
        t->next=temp->next;
        temp->next=t;
        size++;
    }
}
void getvalue_at_index(int idx){
    Node*temp=head;
    if(idx<0 || size<idx) cout<<"Invalid index";
    else if(idx==0) cout<<head->val;
    else if(idx==size-1) cout<<tail->val;
    else{
        for(int i=1;i<=idx;i++){
            temp=temp->next;
        }
        cout<<temp->val;
        size++;
    }
}
void delete_at_head(){
    if(size==0) cout<<"Empty linkedlist";
    else{
        head=head->next;
        size--;
    }
}
void delete_at_tail(){
    if(size==0)cout<<"Invalid linkedlist";
    else{
        Node*temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        tail=temp;
        size--;
    }
}
void delete_at_index(int idx){
    if(idx<0 || size<idx) cout<<"Invalid index";
    else if(size==0) cout<<"list is empty";
    else if(idx==0) delete_at_head();
    else if(size==idx-1) delete_at_tail();
    else{
        Node*temp=head;
        for(int i=1;i<=idx-1;i++){
           temp=temp->next;
        }
        temp->next=temp->next->next;
        size--;
    }
}
int length(){
Node*temp=head;
int n=0;
while(temp->next!=NULL){
    n++;
    temp=temp->next;
}
return n;
}
void display(){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
};
int main(){
Linkedlist ll;
ll.insert_at_beg(89);
ll.display();
ll.insert_at_beg(45);
ll.display();
ll.insert_at_beg(24);
ll.display();
ll.insert_at_beg(78);
ll.display();
ll.insert_at_beg(37);
ll.display();
ll.insert_at_beg(79);
ll.display();


ll.insert_at_end(56);
ll.display();
ll.insert_at_end(76);
ll.display();
ll.insert_at_end(53);
ll.display();
ll.getvalue_at_index(4);
ll.display();
ll.insert_at_index(5,30);
ll.display();
ll.delete_at_head();
ll.display();
ll.delete_at_tail();
ll.display();
ll.delete_at_index(6);
ll.display();
    return 0;
}