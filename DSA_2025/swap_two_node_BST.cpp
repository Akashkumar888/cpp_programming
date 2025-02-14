
void inorder(Node* root, Node*& prev, Node*& first, Node*& second) {
  if (root == NULL) return;

  inorder(root->left, prev, first, second);

  if (prev && prev->data > root->data) { // Detect swapped nodes
      if (first == NULL) first = prev; // First misplaced node
      second = root;  // Second misplaced node (updates to last incorrect)
  }
  prev = root; // Move previous pointer forward

  inorder(root->right, prev, first, second);
}

void correctBST(Node* root) {
  Node* prev = NULL;
  Node* first = NULL;
  Node* second = NULL;

  inorder(root, prev, first, second);

  if (first && second) swap(first->data, second->data); // Swap values to fix BST
}
