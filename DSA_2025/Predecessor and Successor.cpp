
class Solution {
  public:
  void inorder(Node*root,int key,Node* &predecessor,Node* &successor){
      if(root==NULL)return ;
      inorder(root->left,key,predecessor,successor);
      if(root->data<key){
          predecessor=root;
      }
       if(root->data>key && successor==NULL){
          successor=root;
      }
      inorder(root->right,key,predecessor,successor);
  }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node*predecessor=NULL;
        Node*successor=NULL;
        inorder(root,key,predecessor,successor);
        return {predecessor,successor};
    }
  };




  class Solution {
  public:
  void func1(Node*root,int key,Node* &predecessor){
      if(root==NULL)return;
      while(root){
          if(root->data < key){
              predecessor=root;
              root=root->right;
          }
          else{
              root=root->left;
          }
      }
  }
  void func2(Node*root,int key,Node* &successor){
      if(root==NULL)return;
      while(root){
          if(root->data <= key){
              root=root->right;
          }
          else{
              successor=root;
              root=root->left;
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

  