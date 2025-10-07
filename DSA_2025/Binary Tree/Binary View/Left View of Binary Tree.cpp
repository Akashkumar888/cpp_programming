
class Solution {
  public:
  void dfs(Node*root,int depth,vector<int>&result){
      if(root==NULL)return;
      if(depth==result.size())result.push_back(root->data);
      dfs(root->left,depth+1,result);
      dfs(root->right,depth+1,result);
  }
    vector<int> leftView(Node *root) {
        // code here
         vector<int>result;
         dfs(root,0,result);
         return result;
    }
};

// leftside 