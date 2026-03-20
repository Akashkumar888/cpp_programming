/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
//i think dfs use here like postorder
  //root of a BST and an integer key
  //find the inorder predecessor and successor of the given key
  // predecessor means prev and successor means next 
  //inorder -> Left Node Right
  // morris inorder traversal
  //In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor. 
class Solution {
  public:
    void func1(Node*root,int key,Node* &predecessor){
      if(root==NULL)return;
      Node*curr=root;
      while(curr){
          if(curr->data < key){
              predecessor=curr;
              curr=curr->right;
          }
          else{
              curr=curr->left;
          }
      }
  }
  void func2(Node*root,int key,Node* &successor){
      if(root==NULL)return;
       Node*curr=root;
      while(curr){
          if(curr->data > key){
              successor=curr;
              curr=curr->left;
          }
          else{
              curr=curr->right;
          }
      }
  }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node*predecessor=NULL;
        Node*successor=NULL;
        func1(root,key,predecessor);
        func2(root,key,successor);
        return {predecessor,successor};
    }
};


/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  // i think dfs use here like postorder
  //root of a BST and an integer key
  //find the inorder predecessor and successor of the given key
  // predecessor means prev and successor means next 
  //inorder -> Left Node Right
  // morris inorder traversal
  void inorder(Node*root,vector<Node*>&result){
      if(root==NULL)return;
      inorder(root->left,result);
      result.push_back(root);
      inorder(root->right,result);
  }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        
    }
};