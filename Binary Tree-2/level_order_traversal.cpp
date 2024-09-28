


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
void nthlevel(Node*root,int level,int n){
    if(root==NULL) return;
    if(level==n){
    cout<<root->val<<" ";
    }
    nthlevel(root->left,level+1,n);
    nthlevel(root->right,level+1,n);
}
int main(){
    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(5);
    Node* f=new Node(6);
    Node* g=new Node(7);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    nthlevel(a,1,1);
    nthlevel(a,1,2);
    nthlevel(a,1,3);
    return 0;
}