
/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  void bfs(Node*root,map<int,int>&mp){
      if(root==NULL)return ;
      // map keeps keys in ascending order so we can output left->right
      // hd -> node->data (overwritten)
       queue<pair<Node*,int>>q; // node, horizontal distance
       q.push({root,0});
       while(!q.empty()){
           int n=q.size();
           for(int i=0;i<n;i++){
               auto [curr,hr]=q.front();
               q.pop();
               mp[hr]=curr->data; // overwrite: later (lower) nodes replace earlier ones
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
    vector<int> bottomView(Node *root) {
        // code here
        // If there are multiple bottom-most nodes for a horizontal distance from the root,
        // then the latter one in the level order traversal is considered.
        // vertical bottom view that's why we use bfs 
        // vertical traversal , bottom view and top view are similar code only diff of map 
        // vertical traversal  -> map<int,vector<int>>&mp ,bottom view and top view -> map<int,int>mp
        vector<int>result;
        map<int,int>mp;
        bfs(root,mp);
        solve(mp,result);
        return result;
    }
};

// BFS always uses a queue (queue<pair<Node*, int>> q).
// Nodes are visited level by level (top → bottom, left → right).

class Solution {
public:
    vector<int> bottomView(Node *root) {
        if (!root) return {};

        // map keeps keys in ascending order so we can output left->right
        map<int,int> mp;               // hd -> node->data (overwritten)
        queue<pair<Node*,int>> q;      // node, horizontal distance
        q.push({root, 0});

        while (!q.empty()) {
            auto [node, hd] = q.front(); 
            q.pop();
            mp[hd] = node->data;            // overwrite: later (lower) nodes replace earlier ones
            if (node->left)  q.push({node->left,  hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }

        vector<int> result;
        for (auto &p : mp) result.push_back(p.second);
        return result;
    }
};



class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        
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
         ans.push_back(it.second.back());
        }
    return ans;    
    }
};
