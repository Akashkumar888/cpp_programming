
class Solution {
  public:
  void dfs(Node*root,vector<int>&ans,int level){
      if(root==NULL)return;
      if(level==ans.size())ans.push_back(root->data);
      dfs(root->left,ans,level+1);
      dfs(root->right,ans,level+1);
  }
    vector<int> leftView(Node *root) {
        // code here
        vector<int>ans;
        dfs(root,ans,0);
        return ans;
    }
  };
  