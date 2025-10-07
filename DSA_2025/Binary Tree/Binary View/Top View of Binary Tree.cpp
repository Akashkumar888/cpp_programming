
/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  void bfs(Node*root,map<int,int>&mp){
      if(root==NULL)return ;
      // map keeps keys in ascending order so we can output left->right
      // hd -> node->data (not overwritten)
       queue<pair<Node*,int>>q; // node, horizontal distance
       q.push({root,0});
       while(!q.empty()){
           int n=q.size();
           for(int i=0;i<n;i++){
               auto [curr,hr]=q.front();
               q.pop();
              if(mp.find(hr)==mp.end()) mp[hr]=curr->data; // not overwrite: later (lower)does not nodes replace earlier ones
               if(curr->left)q.push({curr->left,hr-1});
               if(curr->right)q.push({curr->right,hr+1});
           }
       }
  }
  void solve(map<int,int>&mp,vector<int>&result){
      for(auto &it:mp){
          result.push_back(it.second);
      }
  }
    vector<int> topView(Node *root) {
        // code here
        // Return the nodes from the leftmost node to the rightmost node.
        // If multiple nodes overlap at the same horizontal position, only the topmost 
        //(closest to the root) node is included in the view. 
        // vertical top view that's why we use bfs 
        vector<int>result;
        map<int,int>mp;
        bfs(root,mp);
        solve(mp,result);
        return result;
    }
};


class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        if(root==NULL)return {};
        vector<int>ans;
        map<int,vector<int>>mp;
        queue<pair<Node*,pair<int,int> > >q;
        q.push({root,{0,0}});
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                Node*node=q.front().first;
                int hd=q.front().second.first;
                int level=q.front().second.second;
                q.pop();
                mp[hd].push_back(node->data);
                if(node->left)q.push({node->left,{hd-1,level+1}});
                if(node->right)q.push({node->right,{hd+1,level+1}});
            }
        }
        for(auto &it:mp){
         ans.push_back(it.second.front());
        }
    return ans;    
    }
};