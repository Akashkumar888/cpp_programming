class Solution {
  public:
  int firstOccurence(int l,int r,vector<int>&arr,int tr){
      int idx=r+1;
      while(l<=r){
          int mid=l+(r-l)/2;
          if(arr[mid]>=tr){
              idx=mid;
              r=mid-1;
          }
          else l=mid+1;
      }
      return idx;
  }
  int lastOccurence(int l,int r,vector<int>&arr,int tr){
      int idx=l-1;
      while(l<=r){
          int mid=l+(r-l)/2;
          if(arr[mid]<=tr){
              idx=mid;
              l=mid+1;
          }
          else r=mid-1;
      }
      return idx;
  }
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        vector<int>result;
        for(auto &que:queries){
            int l=que[0];
            int r=que[1];
            int x=que[2];
            int idx1=firstOccurence(l,r,arr,x);
            int idx2=lastOccurence(l,r,arr,x);
            int count=idx2-idx1+1;
            result.push_back(count);
        }
        return result;
    }
};