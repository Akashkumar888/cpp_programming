
// function should return the number of turns required to go from first node to
// second node
//     A turn is counted when the direction changes (from left to right or vice versa) while going from one node to another.
// To find the number of turns
// Find LCA (Lowest Common Ancestor) of the two given nodes.
// From LCA → first node: count turns.
// From LCA → second node: count turns.
// If LCA is not one of the nodes, total turns = turns(from LCA→first) + turns(from LCA→second) + 1
// (because a turn happens at the LCA when paths diverge).
class Solution {
  public:
    // 🌳 Step 1: Find the Lowest Common Ancestor (LCA)
    Node* lowestCommonAncestor(Node* root, int p, int q) {
        if (root == NULL) return NULL;
        if (root->data == p || root->data == q) return root;

        Node* leftSide = lowestCommonAncestor(root->left, p, q);
        Node* rightSide = lowestCommonAncestor(root->right, p, q);

        // If both sides are non-null → this root is LCA
        if (leftSide && rightSide) return root;
        // Otherwise, return whichever side is non-null
        return (leftSide != NULL) ? leftSide : rightSide;
    }

    // 🔁 Step 2: Recursive helper to find node and count turns
    bool findCount(Node* root, int target, bool cameFromLeft, int& turnCount, bool& found) {
        if (!root || found) return false;

        // ✅ Target node found
        if (root->data == target) {
            found = true;
            return true;
        }

        // Move to left subtree
        if (root->left) {
            if (findCount(root->left, target, true, turnCount, found)) {
                // Turn occurred: right → left
                if (cameFromLeft == false) turnCount++;
                return true;
            }
        }

        // Move to right subtree
        if (root->right) {
            if (findCount(root->right, target, false, turnCount, found)) {
                // Turn occurred: left → right
                if (cameFromLeft == true) turnCount++;
                return true;
            }
        }

        return false; // target not found in this path
    }

    // 🧮 Step 3: Count turns from LCA to a specific node
    int solve(int target, Node* lca) {
        int turnCount = 0;
        bool found = false;

        // Explore both directions from LCA
        if (lca->left)
            findCount(lca->left, target, true, turnCount, found);

        if (lca->right)
            findCount(lca->right, target, false, turnCount, found);

        return turnCount;
    }

    // 🚀 Step 4: Main function to find total number of turns
    int NumberOFTurns(Node* root, int first, int second) {
        if (!root) return 0;

        // Find Lowest Common Ancestor (LCA)
        Node* lca = lowestCommonAncestor(root, first, second);

        // If one node is ancestor of the other → only one path
        if (lca->data == first)
            return solve(second, lca);

        else if (lca->data == second)
            return solve(first, lca);

        // Otherwise → turn at LCA + both path turns
        return 1 + solve(first, lca) + solve(second, lca);
    }
};