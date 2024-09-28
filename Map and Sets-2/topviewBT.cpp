
#include<iostream>
#include<climits>
#include<queue>
#include<unordered_map>
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
void topView(Node*root){
    unordered_map<int,int>mp;// <level,root->val>
    queue<pair<Node*, int> >q; // <node*,level> 

     q.push({root,0});

    // pair<Node*,int>p;
    // p.first=root;
    // p.second=0;
    // q.push(r);
    while(q.size()>0){
    Node*temp=(q.front()).first;
    int level=(q.front()).second;
    q.pop();
    if(mp.find(level)==mp.end()) mp[level]=temp->val;
    if(temp->left!=NULL){
    //     pair<Node*,int>p;
    // p.first=temp->left;
    // p.second=level-1;
    // q.push(p);
     q.push({temp->left,level-1});
    }
    if(temp->right!=NULL){
    //     pair<Node*,int>p;
    // p.first=temp->right;
    // p.second=level+1;
    // q.push(p);
     q.push({temp->right,level+1});
    }
    }
    int minlevel=INT_MAX;
    int maxlevel=INT_MIN;
    for(auto x:mp){
    int level=x.first;
    maxlevel=max(level,maxlevel);
    minlevel=min(level,minlevel);
    }
    for(int i=minlevel;i<=maxlevel;i++){
        cout<<mp[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[]={1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node*root=Construct(arr,n);
    topView(root);
    return 0;
}
