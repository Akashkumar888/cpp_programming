/*
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
  void leftSide(Node*root,vector<int>&result){
      if(root==NULL)return;
      if(root->left==NULL && root->right==NULL)return;
      result.push_back(root->data); // Left Boundary
      if(root->left)leftSide(root->left,result);
      else leftSide(root->right,result);
  }
  void leafNode(Node*root,vector<int>&result){
      if(root==NULL)return;
      if(root->left==NULL && root->right==NULL){
          result.push_back(root->data); // Leaf Nodes
          return;
      }
      leafNode(root->left,result);
      leafNode(root->right,result);
  }
  void rightSide(Node*root,vector<int>&result){
      if(root==NULL)return;
      if(root->left==NULL && root->right==NULL)return;
      if(root->right)rightSide(root->right,result);
      else rightSide(root->left,result);
      result.push_back(root->data); // postorder Reverse Right Boundary
  }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>result;
        if(root)result.push_back(root->data);
        if(root->left)leftSide(root->left,result);
        if(root->left || root->right)leafNode(root,result);
        if(root->right)rightSide(root->right,result);
        return result;
    }
};