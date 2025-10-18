
vector<int> morrisInorderTraversal(Node* root) {
    vector<int> inorder;
    Node* curr = root;

    while (curr) {
        if (curr->left == NULL) {
            inorder.push_back(curr->data);
            curr = curr->right;
        } else {
            Node* pre = curr->left;
            while (pre->right && pre->right != curr)
                pre = pre->right;

            if (pre->right == NULL) {
                pre->right = curr;
                curr = curr->left;
            } else {
                pre->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return inorder; // ascending order (L -> N -> R)
}
