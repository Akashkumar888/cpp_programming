
class Solution {
  public:
  void solve(int i,int n,vector<int>&arr,vector<vector<int>>&result){
      if(i>=n){
          result.push_back(arr);
          return;
      }
      for(int j=i;j<n;j++){
      swap(arr[i],arr[j]);
      solve(i+1,n,arr,result);
      swap(arr[i],arr[j]);
      }
  }
    vector<vector<int>> permuteDist(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>result;
        solve(0,n,arr,result);
        return result;
    }
};
