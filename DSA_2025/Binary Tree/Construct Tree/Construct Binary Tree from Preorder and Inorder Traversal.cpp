class Solution {
public:
TreeNode* solve(int &preIdx,int inStart,int inEnd,vector<int>&preorder,unordered_map<int,int>&mp){
        if(inStart>inEnd) return NULL;
        int val=preorder[preIdx];
        TreeNode*root=new TreeNode(val);
        preIdx++;
        int idx=mp[val];
        if(inStart==inEnd)return root;
        root->left=solve(preIdx,inStart,idx-1,preorder,mp);
        root->right=solve(preIdx,idx+1,inEnd,preorder,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)mp[inorder[i]]=i;
        int preIdx=0;
        return solve(preIdx,0,n-1,preorder,mp);
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
TreeNode* solve(int &preIdx,int st,int ed,vector<int>&preorder,unordered_map<int,int>&mp){
        if(st>ed) return NULL;
        int val=preorder[preIdx];
        TreeNode*root=new TreeNode(val);
        preIdx++;
        int idx=mp[val];
        if(st==ed)return root;
        root->left=solve(preIdx,st,idx-1,preorder,mp);
        root->right=solve(preIdx,idx+1,ed,preorder,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)mp[inorder[i]]=i;
        int preIdx=0;
        return solve(preIdx,0,n-1,preorder,mp);
    }
};

