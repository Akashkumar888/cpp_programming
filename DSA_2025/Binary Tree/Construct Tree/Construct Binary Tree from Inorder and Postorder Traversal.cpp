
class Solution {
public:
TreeNode* solve(int &postIdx,int inStart,int inEnd,vector<int>&postorder,unordered_map<int,int>&mp){
        if(inStart>inEnd) return NULL;
        int val=postorder[postIdx];
        TreeNode*root=new TreeNode(val);
        postIdx--;
        int idx=mp[val];
        if(inStart==inEnd)return root;
        // in reverse order then right then left 
        root->right=solve(postIdx,idx+1,inEnd,postorder,mp);// right
        root->left=solve(postIdx,inStart,idx-1,postorder,mp);//left 
        return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)mp[inorder[i]]=i;
        int postIdx=n-1;
        return solve(postIdx,0,n-1,postorder,mp);
    }
};


class Solution {
public:
TreeNode* solve(int &post_idx,int st,int ed,vector<int>&postorder,unordered_map<int,int>&mp){
        if(st>ed) return NULL;
        int val=postorder[post_idx];
        post_idx--;
        TreeNode*root=new TreeNode(val);
        int idx=mp[val];
        root->right=solve(post_idx,idx+1,ed,postorder,mp);
        root->left=solve(post_idx,st,idx-1,postorder,mp);
        return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)mp[inorder[i]]=i;
        int post_idx=n-1;
        return solve(post_idx,0,n-1,postorder,mp);
    }
};

