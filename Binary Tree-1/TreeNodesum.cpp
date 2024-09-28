

#include<iostream>
using namespace std;
class Node{ // this is a tree node 
public:
int val;
Node*left;
Node*right;

Node(int val){
    this->val=val;
    this->left=NULL;
    this->right=NULL;
}
};
void display(Node *root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
}
int Treesum(Node*root){
    if(root==NULL) return 0;
    int leftsum=Treesum(root->left);
    int rightsum=Treesum(root->right);
    int sum=root->val+leftsum +rightsum;
    return sum;
}
int main(){
    Node* a=new Node(5);
    Node* b=new Node(4);
    Node* c=new Node(3);
    Node* d=new Node(6);
    Node* e=new Node(2);
    Node* g=new Node(1);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->right=g;
    display(a);
    cout<<endl;
    cout<<Treesum(a);
    return 0;
}