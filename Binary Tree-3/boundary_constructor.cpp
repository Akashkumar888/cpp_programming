
 



#include<iostream>
#include<climits>
#include<queue>
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
Node* Construct(int arr[],int n){
    queue<Node*>q;
    Node*root=new Node(arr[0]);
    q.push(root);
    int i=1,j=2;
    while(q.size()!=0 && i<n){
    Node*temp=q.front();
    q.pop();
    Node*l,*r;
    if(arr[i]!=INT_MIN) l=new Node(arr[i]);
    else l=NULL;

    if(j!=n && arr[j]!=INT_MIN) r=new Node(arr[j]);
    else r=NULL;

    temp->left=l;
    temp->right=r;

    if(l!=NULL) q.push(l);
    if(r!=NULL) q.push(r);
    i+=2;
    j+=2;
    }
    return root;
}
int level(Node*root){
    if(root==NULL) return 0;
    return 1+ max(level(root->left),level(root->right));
}
void nthlevel(Node*root,int level,int n){
    if(root==NULL) return;
    nthlevel(root->left,level+1,n);
    nthlevel(root->right,level+1,n);
    if(level==n){
    cout<<root->val<<" ";
    return;
    }
}
void level_order(Node*root){
    int n=level(root);
    for(int i=1;i<=n;i++){
        nthlevel(root,1,i);
        cout<<endl;
    }
}

void leftBoundary(Node*root){
    if(root==NULL)return;
    if(root->left==NULL && root->right==NULL)return;
    cout<<root->val<<" ";
    leftBoundary(root->left);
    if(root->left==NULL) leftBoundary(root->right);

}
void leafBoundary(Node*root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        cout<<root->val<<" ";
    }
    leafBoundary(root->left);
    leafBoundary(root->right);
}
void rightBoundary(Node*root){
    if(root==NULL)return;
    if(root->left==NULL && root->right==NULL)return;
    rightBoundary(root->right);
    if(root->right==NULL) rightBoundary(root->left);
    cout<<root->val<<" ";

}
int main(){
    int arr[]={1,2,3,4,5,INT_MIN,6,7,INT_MIN,8,INT_MIN,9,10,INT_MIN,11,INT_MIN,12,INT_MIN,13,INT_MIN,14,15,16,INT_MIN,17,INT_MIN,INT_MIN,18,INT_MIN,19,INT_MIN,INT_MIN,INT_MIN,20,21,22,23,INT_MIN,24,25,26,27,INT_MIN,INT_MIN,28,INT_MIN,INT_MIN};

    int n=sizeof(arr)/sizeof(arr[0]);
    Node*root=Construct(arr,n);
    // level_order(root);
    // cout<<endl;
    leftBoundary(root);
    cout<<endl;
    leafBoundary(root);
    cout<<endl;
    rightBoundary(root->right);
    return 0;
}
