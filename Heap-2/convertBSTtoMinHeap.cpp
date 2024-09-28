

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
void inorder(Node* root , vector<int> &arr){
if(root==NULL) return ;
inorder(root->left,arr);
arr.push_back(root->val);
inorder(root->right,arr);
}
void print(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void preorder(Node*root,vector<int>&arr,int &idx){
    if(root==NULL)return ;
 root->val=arr[idx];
 idx++;
 preorder(root->left,arr,idx);
 preorder(root->right,arr,idx);
}
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
int main(){
Node*a=new Node(10);
Node*b=new Node(5);
Node*c=new Node(16);
Node*d=new Node(1);
Node*e=new Node(8);
Node*f=new Node(12);
Node*g=new Node(20);
a->left=b,a->right=c;
b->left=d,b->right=e;
c->left=f,c->right=g;
vector<int>arr; // fill in the reverse order
inorder(a,arr);
//print(arr);
levelOrder(a);
int i=0;
preorder(a,arr,i);
cout<<endl;
levelOrder(a);
    return 0;
}