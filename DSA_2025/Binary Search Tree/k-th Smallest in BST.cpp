
class Solution {
  public:
  void inOrder(Node*root,vector<int>&ans){
      if(root==NULL)return ;
      inOrder(root->left,ans);
      ans.push_back(root->data);
      inOrder(root->right,ans);
  }
    int kthSmallest(Node *root, int k) {
        // code here
        vector<int>ans;
        inOrder(root,ans);
        if(k-1<0 || k>ans.size())return -1;
        return ans[k-1];
    }
};


class Solution {
  public:
  // jb bhi inOrder traversal ho BST then use morris traversal
  void morrisInOrder(Node*root,int k,int &kth_element){
      if(root==NULL)return ;
      Node*curr=root;
      int count=1;
      while(curr){
          if(curr->left==NULL){
            if(count==k)kth_element=curr->data;
            curr=curr->right;
            count++;
          }
          else{
              Node*leftChild=curr->left;
              while(leftChild->right){
                  leftChild=leftChild->right;
              }
              leftChild->right=curr;
              // delete node
              Node*temp=curr;
              curr=curr->left;
              temp->left=NULL;
          }
      }
  }
    int kthSmallest(Node *root, int k) {
        // code here
        int kth_element=-1;
        morrisInOrder(root,k,kth_element);
        return kth_element;
    }
};