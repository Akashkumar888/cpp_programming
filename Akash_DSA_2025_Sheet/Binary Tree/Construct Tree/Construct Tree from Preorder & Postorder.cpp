/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
  // &preIdx taki recursion rewind ho to idx vahi pr rahe 
  Node* solve(int &preIdx, int postStart, int postEnd, vector<int> &pre,unordered_map<int,int> &mp) {
        if(postStart > postEnd ) return NULL;
        int val=pre[preIdx];
        Node*root=new Node(val); // node banao jis pr traverse kr rahe ho
        preIdx++;
        // If leaf node, just return
        if (postStart == postEnd) return root;
        // 🔥 Find index of left child (next preorder element) in postorder
            // Find next preorder element in postorder
        int leftChildVal = pre[preIdx];
        int idx = mp[leftChildVal];
        // Build left and right subtrees
        // left subtree = postStart..idx
        root->left = solve(preIdx, postStart, idx, pre, mp);//for left
         // right subtree = idx+1..postEnd-1 (exclude root at postEnd)
        root->right = solve(preIdx, idx + 1, postEnd-1, pre, mp);//for right
        return root;
    }
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        // code here
        // preorder and postorder traversals of a full binary tree. 
        //Your task is to construct the binary tree and return its root.
        // Full Binary Tree is a binary tree where every node has either 0 or 2 children.
        //The preorder and postorder traversals contain unique values,and every 
        //value present in the preorder traversal is also found in the postorder traversal.
        // pre -> NLR
        // post -> RLN
        // ek pr traverse karo
        // ek ka idx map me store lo 
        int n=pre.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)mp[post[i]]=i;
        int preIdx=0;
        return solve(preIdx,0,n-1,pre,mp);
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
// &pre_idx jaha tk array me iterate ho gaya hai uske aage jana hai ab 
// &preIdx taki recursion rewind ho to idx vahi pr rahe 
  TreeNode* solve(int &preIdx, int postStart, int postEnd, vector<int> &pre,unordered_map<int,int> &mp) {
        if(postStart > postEnd ) return NULL;
        int val=pre[preIdx];
        TreeNode*root=new TreeNode(val); // node banao jis pr traverse kr rahe ho
        preIdx++;
        // If leaf node, just return
        if (postStart == postEnd) return root;
        // 🔥 Find index of left child (next preorder element) in postorder
            // Find next preorder element in postorder
        int leftChildVal = pre[preIdx];
        int idx = mp[leftChildVal];
        // Build left and right subtrees
        // left subtree = postStart..idx
        root->left = solve(preIdx, postStart, idx, pre, mp);//for left
         // right subtree = idx+1..postEnd-1 (exclude root at postEnd)
        root->right = solve(preIdx, idx + 1, postEnd - 1, pre, mp);//for right
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=postorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)mp[postorder[i]]=i;
        int preIdx=0;
        return solve(preIdx,0,n-1,preorder,mp);
    }
};
