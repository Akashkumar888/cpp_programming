
/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  void solve(Node*root,vector<int>&ans){
      if(root==NULL)return;
      solve(root->left,ans);
      solve(root->right,ans);
      ans.push_back(root->data);
  }
    vector<int> postOrder(Node* root) {
        // code here
        vector<int>ans;
        solve(root,ans);
        return ans;
    }
};

class Solution {
  public:
  void dfs(Node*root,vector<int>&result){
      if(root==NULL)return;
      dfs(root->left,result);
      dfs(root->right,result);
      result.push_back(root->data);
  }
    vector<int> postOrder(Node* root) {
        // code here
        vector<int>result;
        dfs(root,result);
        return result;
    }
};