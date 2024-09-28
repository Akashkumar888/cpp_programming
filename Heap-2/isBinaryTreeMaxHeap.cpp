
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
public:
int val;
Node*left;
Node*right;
Node(int val){
    left=right=NULL;
    this->val=val;
}
};
void levelOrder(Node*root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}
int sizeoftree(Node*root){
    if(root==NULL) return 0;
    return 1+sizeoftree(root->left) +sizeoftree(root->right);
}
bool isCBT(Node*root){
    int size=sizeoftree(root);
queue<Node*>q;
q.push(root);
int count=0;
while(count<size){
Node*temp=q.front();
q.pop();
count++;
if(temp){
    q.push(temp->left);
    q.push(temp->right);
}
}
while(!q.empty()){
Node*temp=q.front();
if(temp!=NULL)return false;
q.pop();
}
return true;
}
bool isMax(Node*root){
    if(root==NULL)return true;
    if(root->left!=NULL && root->val < root->left->val)return false;
    if(root->right!=NULL && root->val < root->right->val)return false;
    return isMax(root->left) && isMax(root->right);  
}
int main(){
Node*a=new Node(25);
Node*b=new Node(15);
Node*c=new Node(10);
Node*d=new Node(8);
Node*e=new Node(11);
Node*f=NULL;
Node*g=new Node(6);
a->left=b,a->right=c;
b->left=d,b->right=e;
c->left=f,c->right=g;
if(isCBT(a) && isMax(a)) cout<<"Tree is Maxheap";
else cout<<"Tree is not Maxheap";

    return 0;
}