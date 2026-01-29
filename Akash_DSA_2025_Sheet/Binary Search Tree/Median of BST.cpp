
class Solution {
  public:
  void inorder(Node*root,vector<int>&ans){
      if(root==NULL)return;
      inorder(root->left,ans);
      ans.push_back(root->data);
      inorder(root->right,ans);
  }
    int findMedian(Node* root) {
        // Code here
        // If number of nodes are even: return V(n/2)
        // If number of nodes are odd: return V((n+1)/2)
        vector<int>ans;
        inorder(root,ans);
        int n=ans.size();
        if(n%2==0){
            return ans[(n/2)-1];
        }
        else return ans[((n+1)/2)-1];
    }
};



class Solution {
  public:
  int sizeOfTree(Node* root){
      if(root==NULL)return 0;
      return 1+sizeOfTree(root->left)+sizeOfTree(root->right);
  }
  void inorder(Node*root,int n,int &count,int &val){
      if(root==NULL)return;
      inorder(root->left,n,count,val);
      int originalData=root->data;
      count+=1;
      if(n%2==0 && count==(n/2))val=originalData;
      else if(n%2!=0 && count==((n+1)/2))val=originalData;
      inorder(root->right,n,count,val);
  }
    int findMedian(Node* root) {
        // Code here
        // If number of nodes are even: return V(n/2)
        // If number of nodes are odd: return V((n+1)/2)
        int n=sizeOfTree(root);
        int val=0,count=0;
        inorder(root,n,count,val);
        return val;
    }
};

