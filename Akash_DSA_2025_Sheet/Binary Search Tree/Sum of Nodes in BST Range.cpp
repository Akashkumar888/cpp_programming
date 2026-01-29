
class Solution {
  public:
  void dfs(Node*root,int l,int r,int &sum){
      if(root==NULL)return ;
      if(root->data>=l && root->data<=r)sum+=root->data;
      dfs(root->left,l,r,sum);
      dfs(root->right,l,r,sum);
  }
    int nodeSum(Node* root, int l, int r) {
        // code here
        //  sum of all nodes that lie between l and r, including both l and r.
        int sum=0;
        dfs(root,l,r,sum);
        return sum;
    }
};



class Solution {
  public:
  void dfs(Node*root,int l,int r,int &sum){
      if(root==NULL)return ;
      // Include node if within range
      if (root->data >= l && root->data <= r)
          sum += root->data;

      // If current node value > l, explore left subtree
      if (root->data > l)
          dfs(root->left, l, r, sum);

      // If current node value < r, explore right subtree
      if (root->data < r)
          dfs(root->right, l, r, sum);
  }
    int nodeSum(Node* root, int l, int r) {
        // code here
        //  sum of all nodes that lie between l and r, including both l and r.
        int sum=0;
        dfs(root,l,r,sum);
        return sum;
    }
};