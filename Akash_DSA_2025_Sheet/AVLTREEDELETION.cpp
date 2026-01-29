

#include<iostream>
#include<cmath>
using namespace std;
class Node{
  public:
  int data;
  Node*left;
  Node*right;
  int height;
  Node(int val){
    height=1;
    data=val;
    this->left=NULL;
    this->right=NULL;
  }
};

int getHeight(Node*root){
  if(root==NULL)return 0;
  return root->height;
}
int getBalance(Node*root){
  if(root==NULL)return 0;
   return getHeight(root->left) - getHeight(root->right);
}
Node* leftRotation(Node*root){
Node*child=root->right;
Node*childLeft=child->left;

child->left=root;
root->right=childLeft;

//update root the height
root->height=1+max(getHeight(root->left),getHeight(root->right));
//update child the height
child->height=1+max(getHeight(child->left),getHeight(child->right));

return child;
}
Node*rightRotation(Node*root){
Node*child=root->left;
Node*childRight=child->right;

child->right=root;
root->left=childRight;

//update root the height
root->height=1+max(getHeight(root->left),getHeight(root->right));
//update child the height
child->height=1+max(getHeight(child->left),getHeight(child->right));

return child;
}
Node* deleteNode(Node* root, int key) {
    // add code here,
    if (!root) return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // leaf
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }
        // one child
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // two children
        else {
            Node* curr = root->right;
            while (curr->left)
                curr = curr->left;
            root->data = curr->data;
            root->right = deleteNode(root->right, root->data); // ✅ must assign back
        }
    }

    // Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Balance check
    int balance = getBalance(root);

    // LL
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotation(root);

    // LR
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    // RR
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotation(root);

    // RL
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}
void preorder(Node*root){
  if(root==NULL)return;
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}
void inorder(Node*root){
  if(root==NULL)return ;
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}
int main(){
  // duplicate element are not allowed
   // Manually constructing the AVL tree
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    // Updating heights manually (needed for AVL balance)
    root->left->left->height = 1;
    root->left->right->height = 1;
    root->right->left->height = 1;
    root->right->right->height = 1;
    root->left->height = 1 + max(getHeight(root->left->left), getHeight(root->left->right));
    root->right->height = 1 + max(getHeight(root->right->left), getHeight(root->right->right));
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Now test deletion
    root = deleteNode(root, 50);  // Root node
    root = deleteNode(root, 20);  // Leaf
    root = deleteNode(root, 30);  // Node with one child


  cout<<"Preorder:"<<endl;
  preorder(root);
  cout<<endl;
  cout<<"Inorder:"<<endl;
  inorder(root);
  return 0;
}


