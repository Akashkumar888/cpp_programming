
/* Structure for Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

// PreOrder -> Root Left Right
// InOrder ->  Left Root Right
// PostOrder -> Left Right Root
class Solution {
  public:
  int solve(Node* root){
      if(root==NULL)return 0;
      int leftSubTreeSum=solve(root->left);
      int rightSubTreeSum=solve(root->right);
      
      int currentValue = root->data;
      root->data = leftSubTreeSum + rightSubTreeSum;
      return currentValue + leftSubTreeSum + rightSubTreeSum;
  }
    void toSumTree(Node *root) {
        // code here
        solve(root);
    }
};