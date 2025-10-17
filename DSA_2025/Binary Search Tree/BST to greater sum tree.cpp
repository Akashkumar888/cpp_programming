

class Solution {
  public:
//   🧠 Key Idea:
// In a BST, inorder traversal gives nodes in sorted order (ascending).
// The reverse — reverse inorder traversal (right → root → left) — gives nodes in descending order.
// So if we traverse in reverse inorder, we can keep a running sum of all visited nodes — 
//and for each node, we replace its value with the current running sum (which represents the sum of all greater nodes so far).
    
    void reverseInorder(Node* root, int &sum) {
        if (!root) return;

        // Step 1: Go to right subtree (greater values)
        reverseInorder(root->right, sum);

        // Step 2: Replace current node's data with sum of greater nodes
        int original = root->data;
        root->data = sum;

        // Step 3: Add this node's original value to the running sum
        sum += original;

        // Step 4: Go to left subtree (smaller values)
        reverseInorder(root->left, sum);
    }
    void transformTree(Node *root) {
        // code here
        int sum=0;
        reverseInorder(root,sum);
    }
};



class Solution {
  public:
    void inorderStore(Node* root, vector<int> &vals) {
        if (!root) return;
        inorderStore(root->left, vals);
        vals.push_back(root->data);
        inorderStore(root->right, vals);
    }

    void inorderReplace(Node* root, vector<int> &vals, vector<int> &greaterSum, int &idx) {
        if (!root) return;
        inorderReplace(root->left, vals, greaterSum, idx);
        root->data = greaterSum[idx++];  // replace with precomputed greater sum
        inorderReplace(root->right, vals, greaterSum, idx);
    }

    void transformTree(Node *root) {
        if (!root) return;
        vector<int> vals;
        inorderStore(root, vals); // Step 1: store inorder

        int n = vals.size();
        vector<int> greaterSum(n, 0); // Step 2: compute sum of greater elements

        for (int i = n - 2; i >= 0; i--) {
            greaterSum[i] = greaterSum[i + 1] + vals[i + 1];
        }

        int idx = 0;
        inorderReplace(root, vals, greaterSum, idx); // Step 3: replace in inorder order
    }
};
