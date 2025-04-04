#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node*next;
    Node(int val){
        this->next=NULL;
        this->val=val;
    }
};
class stack{
public:
Node*head;
int size;
stack(){
    size=0;
    head=NULL;
}
void push(int val){
    Node*temp=new Node(val);
    temp->next=head;
    head=temp;
    size++;
}
void pop(){
    if(head==NULL){
        cout<<"Stack is empty";
        return ;
    }
    head=head->next;
    size--;
}
int top(){
    if(head==NULL) return -1;
    return head->val;
}
void reversedisplay(){
    Node*temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}
void print(Node*temp){
    if(temp==NULL) return ;
    print(temp->next);
    cout<<temp->val<<" ";
}
void display(){
    Node*temp=head;
    print(temp);
    cout<<endl;
}
};
int main(){
stack st;
st.push(10);
st.push(20);
st.push(30);
st.push(40);
st.push(50);
st.push(60);
cout<<st.size<<endl;
st.display();
st.reversedisplay();
    return 0;
}