

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
int Treesum(Node*root){
    if(root==NULL) return 0;
    int leftsum=Treesum(root->left);
    int rightsum=Treesum(root->right);
    int sum=root->val+leftsum +rightsum;
    return sum;
}
int Treeprod(Node*root){
    if(root==NULL) return 1;
    int leftsum=Treeprod(root->left);
    int rightsum=Treeprod(root->right);
    int product=root->val*leftsum *rightsum;
    return product;
}
int Treesize(Node*root){
 if(root==NULL) return 0;
 int leftsize=Treesize(root->left);
 int rightsize=Treesize(root->right);
 int size= 1+leftsize+rightsize ;
 return size;
}
int maxInTree(Node* root){
if(root==NULL) return INT_MIN;
int leftmax=maxInTree(root->left);
int rightmax=maxInTree(root->right);
return max(root->val,max(leftmax,rightmax));
}
int minInTree(Node* root){
if(root==NULL) return INT_MAX;
int leftmin=minInTree(root->left);
int rightmin=minInTree(root->right);
return min(root->val,min(leftmin,rightmin));
}
int main(){
    Node* a=new Node(2);
    Node* b=new Node(1);
    Node* c=new Node(3);
    Node* d=new Node(12);
    Node* e=new Node(5);
    Node* f=new Node(7);
    Node* g=new Node(6);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    display(a);
    cout<<endl;
    cout<<Treesum(a)<<endl;
    cout<<Treeprod(a)<<endl;
    cout<<Treesize(a)<<endl;
    cout<<maxInTree(a)<<endl;
    cout<<minInTree(a)<<endl;
    return 0;
}
