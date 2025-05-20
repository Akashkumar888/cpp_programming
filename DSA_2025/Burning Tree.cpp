
class Solution {
  public:
  void makegraph(Node*root,unordered_map<int,vector<int>>&mp){
      if(root==NULL)return;
      if(root->left){
          mp[root->data].push_back(root->left->data);
          mp[root->left->data].push_back(root->data);
          makegraph(root->left,mp);
      }
      if(root->right){
          mp[root->data].push_back(root->right->data);
          mp[root->right->data].push_back(root->data);
          makegraph(root->right,mp);
      }
  }
    int minTime(Node* root, int target) {
        // code here
        unordered_map<int,vector<int>>mp;
        makegraph(root,mp);
        unordered_set<int>visited;
         int time = -1; // start with -1 because first level (target) is 0 seconds
        queue<int>q;
        q.push(target);
        visited.insert(target);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
            int curr=q.front();
            q.pop();
            for(auto &ngbr:mp[curr]){
                if(visited.find(ngbr)==visited.end()){
                    q.push(ngbr);
                    visited.insert(ngbr);
                }
            }
            }
            time++;
        }
        return time;
    }
  };




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
// undirected graph 
void makegraph(TreeNode*root,unordered_map<int,vector<int>>&adj){
    if(root==NULL)return;
    if(root->left){
        adj[root->left->val].push_back(root->val);
        adj[root->val].push_back(root->left->val);
        makegraph(root->left,adj);
    }
    if(root->right){
        adj[root->right->val].push_back(root->val);
        adj[root->val].push_back(root->right->val);
        makegraph(root->right,adj);
    }
}
    int amountOfTime(TreeNode* root, int start) {
        int time=0;
        // int ka map yaha start int ka diya hai 
        unordered_map<int,vector<int>>adj;
        unordered_set<int>visited;
        makegraph(root,adj);
        queue<int>q;
        q.push(start);
        visited.insert(start);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                int curr=q.front();
                q.pop();
                for(auto &ngbr:adj[curr]){
                    if(visited.find(ngbr)==visited.end()){
                        q.push(ngbr);
                        visited.insert(ngbr);
                    }
                }
            }
            time++;
        }
        return time-1;
    }
};








/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
// undirected graph 
void makegraph(TreeNode*root,unordered_map<TreeNode*,vector<TreeNode*>>&adj){
    if(root==NULL)return;
    if(root->left){
        adj[root->left].push_back(root);
        adj[root].push_back(root->left);
        makegraph(root->left,adj);
    }
    if(root->right){
        adj[root->right].push_back(root);
        adj[root].push_back(root->right);
        makegraph(root->right,adj);
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        unordered_map<TreeNode*,vector<TreeNode*>>adj;
        unordered_set<TreeNode*>visited;
        makegraph(root,adj);
        queue<TreeNode*>q;
        q.push(target);
        visited.insert(target);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode*curr=q.front();
                q.pop();
                if(k==0)ans.push_back(curr->val);
                for(auto &ngbr:adj[curr]){
                    if(visited.find(ngbr)==visited.end()){
                        q.push(ngbr);
                        visited.insert(ngbr);
                    }
                }
            }
            if(k==0) break; // already collected nodes at distance k
            k--;
        }
        return ans;
    }
};

