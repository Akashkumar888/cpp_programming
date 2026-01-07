
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void bfs(TreeNode*root,int &level){
    queue<TreeNode*>q;
    q.push(root);
    int l=1;
    int maxsum=INT_MIN;
    while(!q.empty()){
        int len=q.size();
        int sum=0;
        for(int i=0;i<len;i++){
            TreeNode*node=q.front();
            q.pop();
            sum+=node->val;
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        if(maxsum<sum){
            maxsum=sum;
            level=l;
        }
        l++;
    }
}
    int maxLevelSum(TreeNode* root) {
        int level=0;
        bfs(root,level);
    return level;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void dfs(TreeNode*root,int level,vector<int>&ans){
    if(root==NULL)return ;
    if(ans.size()<level){
        ans.push_back(0);
    }
    ans[level-1]+=root->val;
    dfs(root->left,level+1,ans);
    dfs(root->right,level+1,ans);
}
    int maxLevelSum(TreeNode* root) {
        vector<int>ans;
        dfs(root,1,ans);
        int height=0,maxsum=INT_MIN;
        for(int i=0;i<ans.size();i++){
            if(maxsum<ans[i]){
                maxsum=ans[i];
                height=i+1;
            }
        }
        return height;
    }
};