#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node*next;
    Node*prev;
    Node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
 };
 class DLL{
public:
int size;
Node* head;
Node* tail;
DLL(){
    head=tail=NULL;
    size=0;
}
void insert_at_tail(int val){
Node * temp=new Node(val);
if(size==0) head=tail=temp;
else{
    tail->next=temp;
    temp->prev=tail; //extra
    tail=temp;
}
size++;
}
void insert_at_head(int val){
Node *temp=new Node(val);
if(size==0) head=tail=temp;
else{
    temp->next=head;
    head->prev=temp; // extra
    head=temp;
}
size++;
}
void insertat_index(int idx,int val){
    if(idx<0 || idx>size) cout<<"Invalid index";
   else if(idx==0){
     insert_at_head(val);
     return ;
    }    
    else if(idx==size){
        insert_at_tail(val);
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
       t->prev=temp; // extra
       t->next->prev=t;// extra
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
        if(head!=NULL) head->prev=NULL;
        if(head==NULL) tail=NULL;
        size--;
    }
}
void delete_at_tail(){
    if(size==0) cout<<"list is empty";
    else if(size==1){
        delete_at_head();
        return;
    }
    Node*temp=tail->prev;
    temp->next=NULL;
    tail=temp;
        size--;
    
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
     temp->next->prev=temp;
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
DLL list;
list.insert_at_tail(10);
list.insert_at_tail(20);
list.insert_at_tail(30);
list.insert_at_tail(40);
list.display();
list.insert_at_tail(50);
list.display();
list.insert_at_head(23);
list.insert_at_head(73);
list.display();
list.insertat_index(3,45);
list.insertat_index(5,55);
list.display();
list.insertat_index(7,75);
list.display();
list.delete_at_head();
list.display();
list.delete_at_tail();
list.display();
list.delete_at_index(2);
list.display();
list.getvalue_at_index(4);
    return 0;
}