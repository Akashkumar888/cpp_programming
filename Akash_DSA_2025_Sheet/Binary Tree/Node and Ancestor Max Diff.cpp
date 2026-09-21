
class Solution {
  public:
    int solve(Node* root,int &ans) {
        // Base case
        if(root == NULL)return INT_MAX;

        // Leaf node
        if(root->left == NULL && root->right == NULL) {
            return root->data;
        }

        // Find minimum value from left and right subtree
        int leftChild = solve(root->left,ans);
        int rightChild = solve(root->right,ans);

        // Minimum descendant of current node
        int minChild = min(leftChild, rightChild);

        // Current node is ancestor
        // minChild is its minimum descendant
        ans = max(ans, root->data - minChild);

        // Return minimum value in current subtree
        return min(root->data, minChild);
    }
    int maxDiff(Node* root) {
        int ans = INT_MIN;
        solve(root,ans);
        return ans;
    }
};