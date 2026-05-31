

/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/
class Solution{
  public:
   int key;
    void solve(Node* root,int i,vector<int> &ans){
        if(root==NULL) return;
        
        ans[i+key]+=root->data;
        solve(root->left,i-1,ans);
        solve(root->right,i+1,ans);
        
    }
    int mini = 1e9;
    int maxi = -1e9;
    void solve1(Node* root,int i){
        if(root==NULL) return;
        mini = min(mini,i);
        maxi = max(maxi,i);
        solve1(root->left,i-1);
        solve1(root->right,i+1);
        
    }
    vector <int> verticalSum(Node *root) {
        // add code here.
          solve1(root,0);
        key=-mini;
        vector<int> ans((-mini)+maxi+1,0);
        solve(root,0,ans);
        return ans;
    }
};



/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
  void bfs(Node* root,map<int,int>&mp){
      if(root==NULL)return ;
      queue<pair<Node*,int>>q;
      q.push({root,0});
      while(!q.empty()){
          Node*curr=q.front().first;
          int ht=q.front().second;
          q.pop();
          mp[ht]+=curr->data;
          if(curr->left)q.push({curr->left,ht-1});
          if(curr->right)q.push({curr->right,ht+1});
      }
  }
  vector<int> verticalView(map<int,int>&mp){
      vector<int>result;
      for(auto &it:mp){
          result.push_back(it.second);
      }
      return result;
  }
    vector<int> verticalSum(Node* root) {
        // code here
        map<int,int>mp;
        bfs(root,mp);
        return verticalView(mp);
    }
};


class Solution {
  public:

    void solve(Node* root,
               int line,
               map<int,int>&mp){

        if(root==NULL) return;

        mp[line]+=root->data;

        solve(root->left,line-1,mp);
        solve(root->right,line+1,mp);
    }

    vector<int> verticalSum(Node *root) {

        map<int,int>mp;

        solve(root,0,mp);

        vector<int>result;

        for(auto &it:mp){
            result.push_back(it.second);
        }

        return result;
    }
};


class Solution {
  public:

    void findRange(Node* root,
                   int line,
                   int &mini,
                   int &maxi){

        if(root==NULL) return;

        mini=min(mini,line);
        maxi=max(maxi,line);

        findRange(root->left,line-1,mini,maxi);
        findRange(root->right,line+1,mini,maxi);
    }

    vector<int> verticalSum(Node *root) {

        int mini=0,maxi=0;

        findRange(root,0,mini,maxi);

        int shift=-mini;

        vector<int>ans(maxi-mini+1,0);

        queue<pair<Node*,int>>q;

        q.push({root,0});

        while(!q.empty()){

            Node* curr=q.front().first;
            int line=q.front().second;
            q.pop();

            ans[line+shift]+=curr->data;

            if(curr->left){
                q.push({curr->left,line-1});
            }

            if(curr->right){
                q.push({curr->right,line+1});
            }
        }

        return ans;
    }
};

