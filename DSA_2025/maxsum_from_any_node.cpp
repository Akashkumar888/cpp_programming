
class Solution {
  public:
      int dfs(Node* root, int &maxsum) {
          if (root == NULL) return 0;
          
          int l = dfs(root->left, maxsum);
          int r = dfs(root->right, maxsum);
          
          int first = l + r + root->data;  // Path passing through root
          int second = max(l, r) + root->data;  // Path including either left or right subtree
          int third = root->data;  // Considering only the root
          
          maxsum = max({maxsum, first, second, third});
          
          return max(second, third);  // Return the best path sum without splitting
      }
  
      int findMaxSum(Node* root) {
          int maxsum = INT_MIN;
          dfs(root, maxsum);
          return maxsum;
      }
  };
  