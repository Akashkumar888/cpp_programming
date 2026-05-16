
class Solution {
public:
    // check if two trees are identical
    bool isSame(TreeNode* a, TreeNode* b){
        // both NULL
        if(a == NULL && b == NULL) return true;
        // one NULL
        if(a == NULL || b == NULL) return false;
        // values differ
        if(a->val != b->val) return false;

        // check left + right
        return isSame(a->left, b->left) && isSame(a->right, b->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // empty subtree always possible
        if(subRoot == NULL) return true;
        // root ended
        if(root == NULL) return false;

        // subtree found
        if(isSame(root, subRoot)) return true;

        // search left OR right
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};



/*
Definition for Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
      // check if two trees are identical
    bool isSame(Node* a, Node* b){
        // both NULL
        if(a == NULL && b == NULL) return true;
        // one NULL
        if(a == NULL || b == NULL) return false;
        // values differ
        if(a->data != b->data) return false;

        // check left + right
        return isSame(a->left, b->left) && isSame(a->right, b->right);
    }
    bool isSubTree(Node *root, Node *subRoot) {
        // code here
        // empty subtree always possible
        if(subRoot == NULL) return true;
        // root ended
        if(root == NULL) return false;

        // subtree found
        if(isSame(root, subRoot)) return true;

        // search left OR right
        return isSubTree(root->left, subRoot) || isSubTree(root->right, subRoot);
    }
};

