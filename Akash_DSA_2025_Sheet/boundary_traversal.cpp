
void left_traversal(Node* root, vector<int>& ans) {
  if (root == NULL || (root->left == NULL && root->right == NULL)) return;
  ans.push_back(root->data);
  if (root->left) left_traversal(root->left, ans);
  else left_traversal(root->right, ans);
}

void leaf_traversal(Node* root, vector<int>& ans) {
  if (root == NULL) return;
  if (root->left == NULL && root->right == NULL) {
      ans.push_back(root->data);
      return;
  }
  leaf_traversal(root->left, ans);
  leaf_traversal(root->right, ans);
}

void right_traversal(Node* root, vector<int>& ans) {
  if (root == NULL || (root->left == NULL && root->right == NULL)) return;
  if (root->right) right_traversal(root->right, ans);
  else right_traversal(root->left, ans);
  ans.push_back(root->data);
}

vector<int> boundaryTraversal(Node *root) {
  vector<int> ans;
  if (root == NULL) return ans;
  
  ans.push_back(root->data); // Always include root
  
  if (root->left) left_traversal(root->left, ans);
  if (root->left || root->right) leaf_traversal(root, ans); // Only collect leaves if not a single node
  if (root->right) right_traversal(root->right, ans);

  return ans;
}
