

class Solution {
  public:
  void dfs(Node* root,vector<int>&temp,vector<vector<int>>&ans){
      if(root==NULL){
          return;
      }
      temp.push_back(root->data);
      if(root->left==NULL && root->right==NULL){
          ans.push_back(temp);
      }
      else{
      dfs(root->left,temp,ans);
      dfs(root->right,temp,ans);
      }
      temp.pop_back();
  }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>>ans;
        vector<int>temp;
        dfs(root,temp,ans);
        return ans;
    }
  };
  