
class Solution {
public:
TreeNode* tree(int &idx,int start,int end,vector<int>&inorder,vector<int>&preorder){
    if(start>end)return NULL;
    int val=preorder[idx];
    TreeNode*root=new TreeNode(val);
    int i=start;
    while(i<=end){
        if(val==inorder[i])break;
        i++;
    }
    idx++;
    root->left=tree(idx,start,i-1,inorder,preorder);
    root->right=tree(idx,i+1,end,inorder,preorder);
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        vector<int>inorder(preorder.begin(),preorder.end());
        sort(inorder.begin(),inorder.end());
        int idx=0;
        return tree(idx,0,n-1,inorder,preorder);
    }
};


class Solution {
public:
TreeNode* solve(int &preIdx,int inStart,int inEnd,vector<int>&preorder,unordered_map<int,int>&mp){
    if(inStart>inEnd)return NULL;
    int val=preorder[preIdx];
    TreeNode*root=new TreeNode(val);
    preIdx++;
    int idx=mp[val];
    if(inStart==inEnd)return root;
    root->left=solve(preIdx,inStart,idx-1,preorder,mp);
    root->right=solve(preIdx,idx+1,inEnd,preorder,mp);
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        vector<int>inorder(preorder.begin(),preorder.end());
        sort(inorder.begin(),inorder.end());
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)mp[inorder[i]]=i;
        int preIdx=0;
        return solve(preIdx,0,n-1,preorder,mp);
    }
};
