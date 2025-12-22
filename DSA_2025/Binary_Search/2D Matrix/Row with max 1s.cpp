
// User function template for C++
class Solution {
  public:
    int firstOccurence(int i,int l,int r,vector<vector<int>>&arr,int tr){
      int idx=r+1;
      while(l<=r){
          int mid=l+(r-l)/2;
          if(arr[i][mid]>=tr){
              idx=mid;
              r=mid-1;
          }
          else l=mid+1;
      }
      return idx;
  }
  int lastOccurence(int i,int l,int r,vector<vector<int>>&arr,int tr){
      int idx=l-1;
      while(l<=r){
          int mid=l+(r-l)/2;
          if(arr[i][mid]<=tr){
              idx=mid;
              l=mid+1;
          }
          else r=mid-1;
      }
      return idx;
  }
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int idx=-1;
        int maxCount=0;
        int n=arr.size();
        int m=arr[0].size();
        for(int i=0;i<n;i++){
            int idx1=firstOccurence(i,0,m-1,arr,1);
            int idx2=lastOccurence(i,0,m-1,arr,1);
            int count=idx2-idx1+1;
            if(count>maxCount){
                maxCount=count;
                idx=i;
            }
        }
        return idx;
    }
};

// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n=arr.size();
        int m=arr[0].size();
        int row = 0, col = m - 1;
        int idx = -1;
        while (row < n && col >= 0) {
            if (arr[row][col] == 1) {
                idx = row;     // current row has more 1s
                col--;         // move left
            } 
            else {
                row++;         // move down
            }
        }
        return idx;
    }
};
