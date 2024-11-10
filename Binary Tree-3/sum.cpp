#include <iostream>
#include <cmath>  // for abs()
using namespace std;

// Definition of the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Recursive function to calculate the difference sum
int f(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) return 0;
    
    // If one tree is NULL, sum the values of the remaining tree
    if (root1 == NULL) {
        return abs(root2->data) + f(NULL, root2->left) + f(NULL, root2->right);
    }
    if (root2 == NULL) {
        return abs(root1->data) + f(root1->left, NULL) + f(root1->right, NULL);
    }

    // Calculate the difference for the current nodes and recurse
    int sum = abs(root1->data - root2->data);
    sum += f(root1->left, root2->left);
    sum += f(root1->right, root2->right);
    return sum;
}

// Function to calculate the total difference sum between two trees
int differenceSum(Node* root1, Node* root2) {
    return f(root1, root2);
}

int main() {
    // Creating two example trees for testing
    Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(7);
    root1->left->left = new Node(1);

    Node* root2 = new Node(5);
    root2->left = new Node(3);
    root2->left->left = new Node(2);

    // Calculating and printing the difference sum
    cout << "Difference Sum: " << differenceSum(root1, root2) << endl;

    return 0;
}
