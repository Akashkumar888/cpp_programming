
/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int>ans;
        Node*curr=root;
        while(curr){
            if(curr->left==NULL){
                ans.push_back(curr->data);
                curr=curr->right;
            }
            else{
                Node*leftChild=curr->left;
                while(leftChild->right){
                    leftChild=leftChild->right;
                }
                leftChild->right=curr;
                //delete node
                Node*temp=curr;
                curr=curr->left;
                temp->left=NULL;
            }
        }
        return ans;
    }
};

// ✅ Morris Inorder Traversal
// (Works for any Binary Tree; for BST → gives sorted order)

void morrisInorder(TreeNode* root) {
    TreeNode* curr = root;
    while (curr) {
        if (!curr->left) {
            cout << curr->val << " ";
            curr = curr->right;
        } else {
            TreeNode* pre = curr->left;
            while (pre->right && pre->right != curr)
                pre = pre->right;

            if (!pre->right) {
                pre->right = curr;   // make thread
                curr = curr->left;
            } else {
                pre->right = NULL;   // remove thread
                cout << curr->val << " ";
                curr = curr->right;
            }
        }
    }
}
