
class Solution {
  public:
//   Given a square matrix mat[][] of size n x n. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space. 
    void rotateMatrix(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        // square matrix of size n x n.
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(int j=0;j<n;j++){
             int l=0,r=n-1;
             while(l<r){
                swap(mat[l][j],mat[r][j]);
                l++,r--;
            }
        }
    }
};
