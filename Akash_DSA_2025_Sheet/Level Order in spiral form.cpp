
// gfg Level Order in spiral form


class Solution {
  public:
  void bfs(Node*root,vector<int>&ans){
      queue<Node*>q;
      q.push(root);
      int level=0;
      while(!q.empty()){
          int n=q.size();
          vector<int>v;
          for(int i=0;i<n;i++){
              Node*curr=q.front();
              q.pop();
              v.push_back(curr->data);
              if(curr->left)q.push(curr->left);
              if(curr->right)q.push(curr->right);
          }
          if(level%2==0)reverse(v.begin(),v.end());
          ans.insert(ans.end(),v.begin(),v.end());
        level++;
      }
  }
    vector<int> findSpiral(Node* root) {
        // code here
        vector<int>ans;
        if(root==NULL)return ans;
        bfs(root,ans);
        return ans;
    }
  };



class Solution {
  public:
  void bfs(Node*root,vector<int>&ans){
      queue<Node*>q;
      q.push(root);
      bool flag=false;
      int level=0;
      while(!q.empty()){
          int n=q.size();
          vector<int>v(n);
          for(int i=0;i<n;i++){
              Node*curr=q.front();
              q.pop();
              int idx=flag ? i : n-1-i;
              v[idx]=curr->data;
              if(curr->left)q.push(curr->left);
              if(curr->right)q.push(curr->right);
          }
          ans.insert(ans.end(),v.begin(),v.end());
          flag=!flag;
      }
  }
    vector<int> findSpiral(Node* root) {
        // code here
        vector<int>ans;
        if(root==NULL)return ans;
        bfs(root,ans);
        return ans;
    }
  };




























  // leetcode 103. Binary Tree Zigzag Level Order Traversal


  /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return {};
    	queue<TreeNode*>q;
    	q.push(root);
    	int level=0;
    	vector<vector<int>>ans;
    	while(!q.empty()){
    	    int n=q.size();
    	    vector<int>v;
    	    for(int i=0;i<n;i++){
    	        TreeNode*node=q.front();
    	        q.pop();
    	        v.push_back(node->val);
    	            if(node->left)q.push(node->left);
    	            if(node->right)q.push(node->right);
    	    }
    	       if(level%2)reverse(v.begin(),v.end());
    	       ans.push_back(v);
               level++;
    	}
    	return ans;
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
    	        int idx=flag? i:n-1-i;
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


