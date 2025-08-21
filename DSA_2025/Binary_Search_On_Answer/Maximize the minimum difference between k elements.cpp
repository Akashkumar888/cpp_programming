
class Solution {
  public:
  bool isPossible(int n,vector<int>&arr,int mid,int k){
      int count = 1;               // first element always chosen
      int last = arr[0];           // last placed element
      for(int i=1; i<n; i++){
          if(arr[i] - last >= mid){
              count++;
              last = arr[i];
              if(count >= k) return true;
          }
      }
      return false;
  }
    int maxMinDiff(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int l=0;
        int r=arr[n-1] - arr[0];
        int ans=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(n,arr,mid,k)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};
// Total Time Complexity
// O(nlogn+nlog(maxDiff))
// Since log(maxDiff) is small (~30), complexity is often dominated by O(n log n) from sorting.
// 👉 Final:
// Time = O(n log n)

// 🔹 Space Complexity
// Sorting done in-place (std::sort) → O(1) auxiliary.
// Binary search and isPossible only use a few variables.
// 👉 Final:
// Space = O(1) (auxiliary)

