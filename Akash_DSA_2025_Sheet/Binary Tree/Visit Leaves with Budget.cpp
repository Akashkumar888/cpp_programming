
class Solution {
public:
    void dfs(Node* root, int level, vector<int>& costs) {
        if (root == nullptr)
            return;

        // Leaf node
        if (root->left == nullptr && root->right == nullptr) {
            costs.push_back(level);
            return;
        }

        dfs(root->left, level + 1, costs);
        dfs(root->right, level + 1, costs);
    }

    int getCount(Node* root, int k) {
        vector<int> costs;

        // Root is at level 1
        dfs(root, 1, costs);

        sort(costs.begin(), costs.end());

        int totalCost = 0;
        int count = 0;

        for (int cost : costs) {
            if (totalCost + cost > k)
                break;

            totalCost += cost;
            count++;
        }

        return count;
    }
};