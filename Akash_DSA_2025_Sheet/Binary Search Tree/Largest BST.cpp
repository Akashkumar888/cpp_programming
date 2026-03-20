
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    // i think postorder use here Left Right Node
    bool dfs(Node*root,int mini,int maxi){
        if(root==NULL)return true;
        if(root->data <=mini || root->data >=maxi)return false;
        return dfs(root->left,mini,root->data) && dfs(root->right,root->data,maxi);
    }
    int sizeOfSubTree(Node* root) {
        if(root==NULL)return 0;
        return 1+sizeOfSubTree(root->left)+sizeOfSubTree(root->right);
    }
    int largestBst(Node *root) {
        // Your code here
        if(root==NULL)return 0;
        if(dfs(root,INT_MIN,INT_MAX))return sizeOfSubTree(root);
        return max(largestBst(root->left),largestBst(root->right));
    }
};



/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class BinarySearchTree {
public:
    int mini;
    int maxi;
    int size;
    BinarySearchTree(int mn,int mx,int sz) {
        this->mini=mn;
        this->maxi=mx;
        this->size=sz;
    }
};
class Solution {
public:
// At each node:
// I need left.maxi and right.mini to decide
// So children MUST return that info
    BinarySearchTree dfs(Node* root) { // here it retrun a class 
        if(root==NULL)return BinarySearchTree(INT_MAX, INT_MIN, 0);
        BinarySearchTree left=dfs(root->left);
        BinarySearchTree right=dfs(root->right);
        if(left.maxi < root->data && right.mini > root->data){
            int mn=min(root->data,left.mini);
            int mx=max(root->data,right.maxi);
            int sz=left.size+right.size + 1;

            return BinarySearchTree(mn,mx,sz);
        }
        // not BST
        return BinarySearchTree(INT_MIN,INT_MAX,max(left.size,right.size));
    }

    int largestBst(Node *root) {
        BinarySearchTree BST = dfs(root);
        return BST.size;
    }
};