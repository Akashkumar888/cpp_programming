
class Solution {
  public:
      Node* LCA(Node* root, Node* n1, Node* n2) {
          if (root == NULL) return NULL;  
          if (root == n1 || root == n2) return root;  
  
          if (root->data > n1->data && root->data > n2->data) 
              return LCA(root->left, n1, n2);  
  
          if (root->data < n1->data && root->data < n2->data) 
              return LCA(root->right, n1, n2);  
  
          return root;  // LCA found
      }
  };
  
// iterative ok
  Node* LCA(Node* root, Node* n1, Node* n2) {
        // code here
        while(root){
        if(root->data > n1->data && root->data > n2->data){
            root=root->left;
        }
        else if(root->data < n1->data && root->data < n2->data){
             root=root->right;
        }
        else break;
        }
        return root;
    }