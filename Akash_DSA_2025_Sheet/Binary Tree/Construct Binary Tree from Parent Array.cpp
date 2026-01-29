
class Solution {
  public:
    Node* createTree(vector<int>& parent) {
        // code here
        int n = parent.size();
        vector<Node*> nodes(n);
        for (int i = 0; i < n; i++)
            nodes[i] = new Node(i);

        Node* root = NULL;

        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                root = nodes[i]; // root found
            } else {
                Node* p = nodes[parent[i]];
                if (p->left == NULL)
                    p->left = nodes[i];
                else
                    p->right = nodes[i];
            }
        }
        return root;
    }
};


class Solution {
  public:
    Node* createTree(vector<int>& parent) {
        // code here
        int n = parent.size();
        map<int, Node*> mp;  // store index -> Node pointer mapping

        // Step 1: Create nodes
        for (int i = 0; i < n; i++)mp[i] = new Node(i);

        Node* root = NULL;

        // Step 2: Link children
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                root = mp[i]; // root node found
            } 
            else {
                Node* p = mp[parent[i]];
                if (p->left==NULL)
                    p->left = mp[i];
                else
                    p->right = mp[i];
            }
        }
        return root;
    }
};
