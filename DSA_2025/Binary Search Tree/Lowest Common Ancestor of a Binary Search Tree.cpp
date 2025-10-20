

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(root==NULL)return NULL;
        // if(root==p || root==q)return root;
        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(root->val < p->val && root->val < q->val){
        return lowestCommonAncestor(root->right,p,q);
        }
        return root; // iski bajah se if else nhi chl raha hai ok 
    }
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
        if(root->val > p->val && root->val > q->val){
            root=root->left;
        }
        else if(root->val < p->val && root->val < q->val){
             root=root->right;
        }
        else break;
        }
        return root;
    }
};
