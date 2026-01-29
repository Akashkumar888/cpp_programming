
/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  void bfs(Node*root,map<int,vector<int>>&mp){
      if(root==NULL)return;
      queue<pair<Node*,int>>q;
      q.push({root,0});
      while(!q.empty()){
          int n=q.size();
          for(int i=0;i<n;i++){
              auto [curr,hr]=q.front();
              q.pop();
              mp[hr].push_back(curr->data);
              if(curr->left)q.push({curr->left,hr-1});
              if(curr->right)q.push({curr->right,hr+1});
          }
      }
  }
  void solve(map<int,vector<int>>&mp,vector<vector<int>>&result){
      for(auto&it:mp){
          result.push_back(it.second);
      }
  }
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        //  If there are multiple nodes passing through a vertical line,
        //then they should be printed as they appear in level order traversal of the tree.
        // vertical traversal , bottom view and top view are similar code only diff of map map<int,vector<int>>&mp
        // vertical traversal , bottom view and top view are similar code only diff of map 
        // vertical traversal  -> map<int,vector<int>>&mp ,bottom view and top view -> map<int,int>mp
        map<int,vector<int>>mp;
        vector<vector<int>>result;
        bfs(root,mp);
        solve(mp,result);
        return result;
    }
};