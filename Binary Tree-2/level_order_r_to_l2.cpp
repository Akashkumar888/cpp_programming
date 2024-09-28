


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
int level(Node*root){
    if(root==NULL) return 0;
    return 1+ max(level(root->left),level(root->right));
}
void nthlevel(Node*root,int level,int n){
    if(root==NULL) return;
    nthlevel(root->right,level+1,n);
    if(level==n){
    cout<<root->val<<" ";
    return;
    }
    nthlevel(root->left,level+1,n);
}
void level_order(Node*root){
    int n=level(root);
    for(int i=1;i<=n;i++){
        nthlevel(root,1,i);
        cout<<endl;
    }
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
    level_order(a);
    return 0;
}