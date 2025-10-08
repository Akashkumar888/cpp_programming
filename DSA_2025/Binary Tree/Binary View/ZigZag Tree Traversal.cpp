
/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  void bfs(Node*root,vector<int>&result){
      if(root==NULL)return;
      queue<Node*>q;
      bool flip=false;
      q.push(root);
      while(!q.empty()){
          int n=q.size();
          vector<int>ans(n);
          for(int i=0;i<n;i++){
              Node*curr=q.front();
              q.pop();
              ans[i]=(curr->data);
              if(curr->left)q.push(curr->left);
              if(curr->right)q.push(curr->right);
          }
          if(flip){
              reverse(ans.begin(),ans.end());
          }
          for(int i=0;i<n;i++)result.push_back(ans[i]);
          flip=!flip;
      }
  }
    vector<int> zigZagTraversal(Node* root) {
        // code here
        // In zig zag traversal we traverse the nodes from left to right for odd-numbered levels, 
        //and from right to left for even-numbered levels.
        vector<int>result;
        bfs(root,result);
        return result;
    }
};

/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  void bfs(Node*root,vector<int>&result){
      if(root==NULL)return;
      queue<Node*>q;
      bool flip=true;
      q.push(root);
      while(!q.empty()){
          int n=q.size();
          vector<int>ans(n);
          for(int i=0;i<n;i++){
              Node*curr=q.front();
              q.pop();
              ans[flip ? i : n-1-i]=(curr->data);
              if(curr->left)q.push(curr->left);
              if(curr->right)q.push(curr->right);
          }
          for(int i=0;i<n;i++)result.push_back(ans[i]);
          flip=!flip;
      }
  }
    vector<int> zigZagTraversal(Node* root) {
        // code here
        // In zig zag traversal we traverse the nodes from left to right for odd-numbered levels, 
        //and from right to left for even-numbered levels.
        vector<int>result;
        bfs(root,result);
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return {};
    	queue<TreeNode*>q;
    	q.push(root);
    	bool flag=true;
    	vector<vector<int>>ans;
    	while(!q.empty()){
    	    int n=q.size();
    	    vector<int>v(n);
    	    for(int i=0;i<n;i++){
    	        TreeNode*node=q.front();
    	        q.pop();
    	        int idx=flag ? i : n-1-i; // starting : ending idx
    	        v[idx]=(node->val);
    	            if(node->left)q.push(node->left);
    	            if(node->right)q.push(node->right);
    	    }
    	       flag=!flag;
    	       ans.push_back(v);
    	}
    	return ans;
    }
};