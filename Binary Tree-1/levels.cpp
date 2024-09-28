

#include<iostream>
#include<climits>
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
int Treelevel(Node*root){
    if(root==NULL) return 0;
    int leftlevel=Treelevel(root->left);
    int rightlevel=Treelevel(root->right);
    return 1+max(leftlevel,rightlevel);
}
int Treeheight(Node*root){
    if(root==NULL) return 0;
    int leftheight=Treeheight(root->left);
    int rightheight=Treeheight(root->right);
    return 1+max(leftheight,rightheight);
}
int main(){
    Node* a=new Node(2);
    Node* b=new Node(1);
    Node* c=new Node(3);
    Node* d=new Node(12);
    Node* e=new Node(5);
    Node* f=new Node(7);
    Node* g=new Node(6);
    Node* h=new Node(8);
    Node* i=new Node(9);
    Node* j=new Node(10);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    g->left=h;
    g->right=i;
    i->left=j;
    display(a);
    cout<<endl;
    cout<<Treelevel(a)<<endl;
    cout<<Treeheight(a)-1<<endl;
    return 0;
}
