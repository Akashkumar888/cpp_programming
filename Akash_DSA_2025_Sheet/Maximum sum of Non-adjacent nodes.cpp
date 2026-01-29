
pair<int, int> solve(Node* root) {
  if (!root) return {0, 0};
  
  auto left = solve(root->left);
  auto right = solve(root->right);
  
  // Include root: root->data + exclude left + exclude right
  int incl = root->data + left.second + right.second;
  
  // Exclude root: max of include or exclude left + max of include or exclude right
  int excl = max(left.first, left.second) + max(right.first, right.second);
  
  return {incl, excl};
}

int getMaxSum(Node *root) {
  auto res = solve(root);
  return max(res.first, res.second);
}

