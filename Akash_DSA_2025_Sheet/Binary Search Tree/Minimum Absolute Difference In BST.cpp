
/* Binary Tree Node Structure
class Node {
	public:
	int data;
	Node *left;
	Node *right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
};
*/

class Solution {
	public:
	// here i think use inorder because inorder traversal is sorted order
	void inorder(Node* root, Node* &prevNode, int &absDiff) {
		if (root == NULL)return;
		inorder(root->left, prevNode, absDiff);
		// Compare with previous inorder element
		if (prevNode ) {
			absDiff = min(absDiff, root->data - prevNode->data);
		}
		prevNode = root;
		inorder(root->right, prevNode, absDiff);
	}
	int absDiff(Node *root) {
		// code here
		Node* prevNode = NULL;
		int absDiff = INT_MAX;
		inorder(root, prevNode, absDiff);
		return absDiff;
	}
};
