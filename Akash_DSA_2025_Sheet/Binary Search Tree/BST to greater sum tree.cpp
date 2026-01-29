

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


class Solution {
public:
    // Morris Reverse Inorder traversal that also updates nodes for Greater Sum Tree
    void morrisReverseInOrder(Node* root) {
        if (root == NULL) return;

        Node* curr = root;
        int sum = 0; // running sum of all greater nodes

        while (curr) {
            // Case 1: no right child, visit current node
            if (curr->right == NULL) {
                // Step 1: Store original value
                int original = curr->data;

                // Step 2: Replace current node's value with sum of greater nodes
                curr->data = sum;

                // Step 3: Update running sum
                sum += original;

                // Step 4: Move to left subtree
                curr = curr->left;
            }
            // Case 2: right child exists
            else {
                Node* rightChild = curr->right;

                // Find the inorder predecessor in the right subtree
                while (rightChild->left && rightChild->left != curr) {
                    rightChild = rightChild->left;
                }

                // Create a temporary thread to current node if it doesn't exist
                if (rightChild->left == NULL) {
                    rightChild->left = curr;
                    curr = curr->right;
                }
                // Thread exists, visit current node and remove the thread
                else {
                    rightChild->left = NULL; // remove thread

                    int original = curr->data;
                    curr->data = sum; // update node value
                    sum += original;  // update running sum

                    curr = curr->left;
                }
            }
        }
    }

    void transformTree(Node* root) {
        morrisReverseInOrder(root);
    }
};



class Solution {
public:
    // Perform Morris Reverse Inorder traversal to transform BST into Greater Sum Tree
    void morrisReverseInOrder(Node* root) {
        if (root == NULL) return;

        Node* curr = root;
        int sum = 0; // running sum of all greater nodes

        while (curr) {
            // Case 1: No right child
            if (curr->right == NULL) {
                int original = curr->data;
                curr->data = sum; // replace current node with sum of greater nodes
                sum += original;  // update running sum
                curr = curr->left; // move to left subtree
            }
            // Case 2: Right child exists
            else {
                Node* succ = curr->right;
                // Find the inorder predecessor in the right subtree (leftmost node)
                while (succ->left && succ->left != curr)
                    succ = succ->left;

                // Make thread if not done yet
                if (succ->left == NULL) {
                    succ->left = curr;
                    curr = curr->right;
                } 
                // Thread exists — remove it and visit current node
                else {
                    succ->left = NULL;

                    int original = curr->data;
                    curr->data = sum; // update current node
                    sum += original;  // update running sum

                    curr = curr->left; // move to left subtree
                }
            }
        }
    }

    void transformTree(Node* root) {
        morrisReverseInOrder(root);
    }
};

