
#include<iostream>
#include<cmath>
using namespace std;
class Node{
  public:
  int data;
  Node*left;
  Node*right;
  int height;
  Node(int val){
    height=1;
    data=val;
    this->left=NULL;
    this->right=NULL;
  }
};
int getHeight(Node*root){
  if(root==NULL)return 0;
  return root->height;
}
int getBalance(Node*root){
  if(root==NULL)return 0;
   return getHeight(root->left) - getHeight(root->right);
}
Node* leftRotation(Node*root){
Node*child=root->right;
Node*childLeft=child->left;

child->left=root;
root->right=childLeft;

//update root the height
root->height=1+max(getHeight(root->left),getHeight(root->right));
//update child the height
child->height=1+max(getHeight(child->left),getHeight(child->right));

return child;
}
Node*rightRotation(Node*root){
Node*child=root->left;
Node*childRight=child->right;

child->right=root;
root->left=childRight;

//update root the height
root->height=1+max(getHeight(root->left),getHeight(root->right));
//update child the height
child->height=1+max(getHeight(child->left),getHeight(child->right));

return child;
}

Node* insert(Node*root,int key){
if(root==NULL)return new Node(key);

if(key<root->data){
  root->left=insert(root->left,key);
}
else if(key>root->data){
  root->right=insert(root->right,key);
}
else return root;

root->height=1+max(getHeight(root->left),getHeight(root->right));

int balance=getBalance(root);

// left left case
if(balance>1 && key < root->left->data){
return rightRotation(root); // top element ko 
}
// right right case
else if(balance<-1 && key>root->right->data){
return leftRotation(root);// r=top element ko
}
// left right case
else if(balance>1 && key>root->left->data){
root->left=leftRotation(root->left);// means middle element ko
return rightRotation(root);// top element ko
}
// right left case
else if(balance<-1 && key < root->right->data){
root->right=rightRotation(root->right);// means middle element ko
return leftRotation(root);// top element ko
}
// no balancing
else return root;

}

void preorder(Node*root){
  if(root==NULL)return;
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}
void inorder(Node*root){
  if(root==NULL)return ;
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}
int main(){
  // duplicate element are not allowed
  Node *root=NULL;
  root=insert(root,10);
  root=insert(root,20);
  root=insert(root,30);
  root=insert(root,50);
  root=insert(root,70);
  root=insert(root,5);
  root=insert(root,100);
  root=insert(root,95);

  cout<<"Preorder:"<<endl;
  preorder(root);
  cout<<endl;
  cout<<"Inorder:"<<endl;
  inorder(root);
  return 0;
}

