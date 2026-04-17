class Node {
public:
    int data;
    int idx;
    Node* left;
    Node* right;
    Node(int val, int i) {
        data = val;
        idx = i;
        left = NULL;
        right = NULL;
    }
};
class Solution {
public:
    void solve(Node* root, string temp, vector<string>& result) {
        if (root == NULL) return;
        // leaf node
        if (root->left == NULL && root->right == NULL) {
            result.push_back(temp);
            return;
        }
        solve(root->left, temp + "0", result);
        solve(root->right, temp + "1", result);
    }

    vector<string> huffmanCodes(string &s, vector<int> f) {
        int n = f.size();
        if (n == 1) {
            return {"0"};
        }
        auto cmp = [](Node* a, Node* b) {
            if (a->data == b->data) return a->idx > b->idx;
            return a->data > b->data;
        };
        priority_queue<Node*, vector<Node*>, decltype(cmp)> pq(cmp);
        // step 1
        for (int i = 0; i < n; i++) {
            pq.push(new Node(f[i], i));
        }
        // step 2
        while (pq.size() > 1) {
            Node* left = pq.top(); pq.pop();
            Node* right = pq.top(); pq.pop();

            int newIdx = min(left->idx, right->idx);

            Node* parent = new Node(left->data + right->data, newIdx);
            parent->left = left;
            parent->right = right;

            pq.push(parent);
        }
        Node* root = pq.top();
        vector<string> result;
        // step 3
        solve(root, "", result);
        return result;
    }
};
