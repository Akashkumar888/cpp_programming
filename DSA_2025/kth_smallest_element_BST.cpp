
class Solution {
  public:
      void inorder(Node* root, int k, int &count, int &minval) {
          if (root == NULL) return;
          
          inorder(root->left, k, count, minval);  // Visit left subtree
          
          count++;  
          if (count == k) {  
              minval = root->data;  // Store the k-th smallest element
              return;
          }
  
          inorder(root->right, k, count, minval);  // Visit right subtree
      }
  
      int kthSmallest(Node *root, int k) {
          int minval = INT_MAX;  // Stores the result
          int count = 0;         // Tracks number of visited nodes
          
          inorder(root, k, count, minval);
          
          return (minval == INT_MAX) ? -1 : minval;  // If k is out of range, return -1
      }
  };
  