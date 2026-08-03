
class Solution {
  public:
    void dfs(Node* root, int len,int &ans) {
        if(root == NULL)return;
        ans = max(ans, len);
        if(root->left) {
            if(root->left->data == root->data + 1) dfs(root->left, len + 1,ans);
            else dfs(root->left, 1,ans);
        }
        if(root->right) {
            if(root->right->data == root->data + 1)dfs(root->right, len + 1,ans);
            else dfs(root->right, 1,ans);
        }
    }
    int longestConsecutive(Node* root) {
        if(root == NULL) return -1;
        int ans=1;
        dfs(root, 1,ans);
        if(ans == 1) return -1;
        return ans;
    }
};