
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

      cout << "Traversing in ascending order:\n";
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " -> ";
        for (int val : it->second) cout << val << " ";
        cout << "\n";
    }

    cout << "\nTraversing in descending order:\n";
    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        cout << it->first << " -> ";
        for (int val : it->second) cout << val << " ";
        cout << "\n";
    }

// mp.rbegin() ka type hota hai map<int,vector<int>>::reverse_iterator.
// Reverse iterator me ++ ka matlab hota hai aage "reverse direction" me jaana, matlab chhote keys ki taraf.
// Agar tum it-- karoge to wo ulta direction ho jayega (greater se aur bada key ki taraf move karega, jo exist hi nahi karta).

class Solution {
  public:
  void dfs(Node*root,int l,int r,map<int,vector<int>>&mp){
      if(root==NULL)return;
      mp[l].push_back(root->data);
      dfs(root->left,l+1,r,mp);
      dfs(root->right,l,r+1,mp);
  }
  void solve(vector<int>&result,map<int,vector<int>>&mp){
    for(auto it=mp.begin();it!=mp.end();it++){
        for(int &val: it->second)result.push_back(val);
    }
  }
    vector<int> diagonal(Node *root) {
        // code here
        // If the diagonal element are present in two different subtrees then
        //left subtree diagonal element should be taken first and then right subtree.
        // here l,r to value for left and right turn 
        // here main diagonal that why we only use l 
        vector<int>result;
        map<int,vector<int>>mp;
        dfs(root,0,0,mp);
        solve(result,mp);
        return result;
    }
};


// main diagonal traverse 
class Solution {
  public:
  void dfs(Node*root,int l,map<int,vector<int>>&mp){
      if(root==NULL)return;
      mp[l].push_back(root->data);
      dfs(root->left,l+1,mp); // left me jao l+1 // left child → increase diagonal index
      dfs(root->right,l,mp); // right me jao l same  // right child → stay in same diagonal
  }
  void solve(vector<int>&result,map<int,vector<int>>&mp){
    for(auto it=mp.begin();it!=mp.end();it++){
        for(int &val: it->second)result.push_back(val);
    }
  }
    vector<int> diagonal(Node *root) {
        // code here
        // If the diagonal element are present in two different subtrees then
        //left subtree diagonal element should be taken first and then right subtree.
        // here l,r to value for left and right turn 
        // here main diagonal that why we only use l 
        vector<int>result;
        map<int,vector<int>>mp;
        dfs(root,0,mp);
        solve(result,mp);
        return result;
    }
};
// Left child → new diagonal (l+1)
// Right child → same diagonal (l)


// Anti-Diagonal Code
class Solution {
  public:
  void dfs(Node* root, int r, map<int,vector<int>>& mp){ 
      if(root == NULL) return;
      mp[r].push_back(root->data);   // ✅ should use r

      dfs(root->left, r, mp);        // left child stays in same anti-diagonal
      dfs(root->right, r+1, mp);     // right child goes to next anti-diagonal
  }

  void solve(vector<int>& result, map<int,vector<int>>& mp){
      for(auto it = mp.begin(); it != mp.end(); it++){
          for(int &val: it->second) result.push_back(val);
      }
  }

  vector<int> diagonal(Node *root) {
      vector<int> result;
      map<int,vector<int>> mp;
      dfs(root, 0, mp);
      solve(result, mp);
      return result;
  }
};
// Anti-Diagonal →
// left → r,
// right → r+1

// diagonal traverse in binary tree or matrix always use ordered map and analyze pattern 

class Solution {
public:
void diagonal(vector<vector<int>>& mat,map<int,vector<int>>&mp){
      for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            mp[i+j].push_back(mat[i][j]);
        }
      }
  }
  void solve(vector<int>&result,map<int,vector<int>>&mp){
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->first%2==0)reverse(it->second.begin(),it->second.end());
        for(int &val: it->second)result.push_back(val);
    }
  }
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>result;
        map<int,vector<int>>mp;
        diagonal(mat,mp);
        solve(result,mp);
        return result;
    }
}; 

class Solution {
public:
void diagonal(vector<vector<int>>& mat,map<int,vector<int>>&mp){
      for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            mp[i+j].push_back(mat[i][j]);
        }
      }
  }
  void solve(vector<int>&result,map<int,vector<int>>&mp){
    for(auto it=mp.begin();it!=mp.end();it++){
        reverse(it->second.begin(),it->second.end());
        for(int &val: it->second)result.push_back(val);
    }
  }
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int>result;
        map<int,vector<int>>mp;
        diagonal(nums,mp);
        solve(result,mp);
        return result;
    }
}; 

//  when we use this type of for loop 
//  for(auto it=mp.begin();it!=mp.end();it++){
//         reverse(it->second.begin(),it->second.end());
//         for(int &val: it->second)result.push_back(val);
//     } 
//     then we use -> operator
     
    
    // when this type of for loop 
    // for(auto &it:mp){
    //     reverse(it.second.begin(),it.second.end());
    //     for(int &val: it.second)result.push_back(val);
    // } 
    // then we use . operator in cpp 

