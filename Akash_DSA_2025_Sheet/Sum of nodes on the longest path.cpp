
class Solution {
  public:
  void dfs(Node*root,int sum,int len,int &maxlen,int &maxSum){
      if(root==NULL)return;
      sum+=root->data;
      len+=1;
      if(root->left==NULL && root->right==NULL){
          if(len>maxlen){
              maxlen=len;
              maxSum=sum;
          }
          else if(len==maxlen)maxSum=max(maxSum,sum);
      }
      dfs(root->left,sum,len,maxlen,maxSum);
      dfs(root->right,sum,len,maxlen,maxSum);
  }
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        int maxSum=0,maxlen=0;
        dfs(root,0,0,maxlen,maxSum);
        return maxSum;
    }
};
