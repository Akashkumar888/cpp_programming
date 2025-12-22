class Solution {
  public:
//   count how many elements in arr[] lie within the range [a, b], i.e., elements satisfying a ≤ x ≤ b.
  int lowerCase(vector<int>&arr,int &tr){
      int l=0,r=arr.size()-1;
      int idx = arr.size();   // IMPORTANT
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
  int upperCase(vector<int>&arr,int &tr){
      int l=0,r=arr.size()-1;
      int idx = -1;   // IMPORTANT
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
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        sort(arr.begin(),arr.end());
        vector<int>result;
        for(auto &que:queries){
            int a=que[0];
            int b=que[1];
            int idx2=upperCase(arr,b);
            if(idx2==-1)result.push_back(0);
            else{
            int idx1=lowerCase(arr,a);
            int count=idx2-idx1+1;
            result.push_back(count);
            }
        }
        return result;
    }
};