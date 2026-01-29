
int kthSmallest(Node *root, int k) {
  // add code here.
  int minval=INT_MAX;
  int count=0;
  Node*curr=root;
  while(curr){
      if(curr->left==NULL){
          count++;
          if(count==k)minval=curr->data;
          curr=curr->right;
      }
      else{
          Node*leftChild=curr->left;
          while(leftChild->right){
              leftChild=leftChild->right;
          }
          leftChild->right=curr;
          // delte node ok
          Node* temp=curr;
          curr=curr->left;
          temp->left=NULL;
      }
  }
  if(minval==INT_MAX)return -1;
  return minval;
}