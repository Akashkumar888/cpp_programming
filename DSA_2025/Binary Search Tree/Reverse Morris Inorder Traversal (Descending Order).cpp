
vector<int> reverseMorrisInorderTraversal(Node* root) {
    vector<int> inorder;
    Node* curr = root;

    while (curr) {
        if (curr->right == NULL) {
            inorder.push_back(curr->data);
            curr = curr->left;
        } else {
            Node* succ = curr->right;
            while (succ->left && succ->left != curr)
                succ = succ->left;

            if (succ->left == NULL) {
                succ->left = curr;
                curr = curr->right;
            } else {
                succ->left = NULL;
                inorder.push_back(curr->data);
                curr = curr->left;
            }
        }
    }
    return inorder; // descending order (R -> N -> L)
}

