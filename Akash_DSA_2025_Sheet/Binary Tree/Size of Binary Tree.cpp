
/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/


class Solution {
  public:
  int solve(Node* root){
      if(root==NULL)return 0;
      return 1 + solve(root->left) + solve(root->right);
  }
    int getSize(Node* root) {
        // code here
        return solve(root);
    }
};


class Solution {
  public:
    int getSize(Node* root) {
        if(root == NULL) return 0;

        queue<Node*> q;
        q.push(root);

        int count = 0;

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            count++;

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

        return count;
    }
};


class Solution {
  public:
    int getSize(Node* root) {
        if(root == NULL) return 0;

        stack<Node*> st;
        st.push(root);

        int count = 0;

        while(!st.empty()){
            Node* curr = st.top();
            st.pop();

            count++;

            if(curr->left) st.push(curr->left);
            if(curr->right) st.push(curr->right);
        }

        return count;
    }
};


class Solution {
  public:
    int getSize(Node* root) {
        Node* curr = root;
        int count = 0;

        while(curr){
            if(curr->left == NULL){
                count++;
                curr = curr->right;
            }
            else{
                Node* pred = curr->left;

                while(pred->right && pred->right != curr){
                    pred = pred->right;
                }

                if(pred->right == NULL){
                    pred->right = curr;
                    curr = curr->left;
                }
                else{
                    pred->right = NULL;
                    count++;
                    curr = curr->right;
                }
            }
        }

        return count;
    }
};


class Solution {
  public:
  void dfs(Node*root,int &Size){
      if(root==NULL)return;
      Size++;
      dfs(root->left,Size);
      dfs(root->right,Size);
  }
    int getSize(Node* node) {
        // code here
        int Size=0;
        dfs(node,Size);
        return Size;
    }
};
