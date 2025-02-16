
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Preorder traversal for serialization
void preorder(Node* root, vector<int>& ans) {
    if (root == NULL) {
        ans.push_back(0); // Mark NULL nodes as 0
        return;
    }
    ans.push_back(root->data);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

// Serialize a tree into a list
vector<int> serialize(Node* root) {
    vector<int> ans;
    preorder(root, ans);
    return ans;
}

// Helper function for deserialization (named as 'akash')
Node* akash(int &idx, vector<int>& arr) {
    if (idx >= arr.size() || arr[idx] == 0) {
        idx++;  // Move to the next index
        return NULL;
    }

    // Create a new node
    Node* newnode = new Node(arr[idx++]);

    // Recursively construct left and right subtrees
    newnode->left = akash(idx, arr);
    newnode->right = akash(idx, arr);

    return newnode;
}

// Wrapper function for deserialization
Node* deSerialize(vector<int>& arr) {
    int idx = 0;
    return akash(idx, arr);
}

// Helper function to print inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Serialize the tree
    vector<int> serializedData = serialize(root);
    cout << "Serialized Data: ";
    for (int val : serializedData) cout << val << " ";
    cout << endl;

    // Deserialize the list back to a tree
    Node* deserializedRoot = deSerialize(serializedData);

    // Verify by printing inorder traversal
    cout << "Inorder Traversal of Deserialized Tree: ";
    inorder(deserializedRoot);
    cout << endl;

    return 0;
}
