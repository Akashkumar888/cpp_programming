
class Solution {
  public:
  void dfs(Node*root,int depth,vector<int>&result){
      if(root==NULL)return;
      if(depth==result.size())result.push_back(root->data);
      dfs(root->right,depth+1,result);
      dfs(root->left,depth+1,result);
  }
    vector<int> rightView(Node *root) {
        //  code here
        vector<int>result;
         dfs(root,0,result);
         return result;
    }
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        if(root==NULL)return {};
        // dfs(root,0,result);
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode*curr=q.front();
                q.pop();
                if(i==n-1)result.push_back(curr->val);
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
        }
        return result;
    }
};