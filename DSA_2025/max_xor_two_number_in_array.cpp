
class TrieNode {
  public:
      TrieNode* left;
      TrieNode* right;
  };
  
  class Solution {
  public:
      TrieNode* root;
      Solution() {
          root = new TrieNode();
      }
  
      void insert(int &num) {
          TrieNode* crawl = root;
          for (int i = 31; i >= 0; i--) {
              int ith_bit = (num >> i) & 1;
              if (ith_bit == 0) {
                  if (crawl->left == NULL) {
                      crawl->left = new TrieNode();
                  }
                  crawl = crawl->left;
              } else {
                  if (crawl->right == NULL) {
                      crawl->right = new TrieNode();
                  }
                  crawl = crawl->right;
              }
          }
      }
  
      int search(int &num) {
          int max_Xor = 0;
          TrieNode* crawl = root;
          for (int i = 31; i >= 0; i--) {
              int ith_bit = (num >> i) & 1;
              if (ith_bit == 1) {
                  if (crawl->left != NULL) {
                      max_Xor += (1 << i);
                      crawl = crawl->left;
                  } else {
                      crawl = crawl->right;
                  }
              } else {
                  if (crawl->right != NULL) {
                      max_Xor += (1 << i);
                      crawl = crawl->right;
                  } else {
                      crawl = crawl->left;
                  }
              }
          }
          return max_Xor;
      }
  
      int maxXor(vector<int> &arr) {
          for (int &num : arr) insert(num);
          int maxVal = 0;
          for (int &num : arr) {
              maxVal = max(maxVal, search(num));
          }
          return maxVal;
      }
  };
  