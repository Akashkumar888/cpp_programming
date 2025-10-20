
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==NULL)return NULL;
       if(root==p || root==q)return root;

       TreeNode* leftSide=lowestCommonAncestor(root->left,p,q);
       TreeNode* rightSide=lowestCommonAncestor(root->right,p,q);
       if(leftSide!=NULL && rightSide!=NULL) return root; 
       if(leftSide!=NULL && rightSide==NULL)return leftSide;
    //    if(leftSide==NULL && rightSide!=NULL)
       return rightSide;
    }
};
