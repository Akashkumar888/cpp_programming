
class Solution {
  public:
  int last_occurence(int n,vector<int>&arr,int tr,int i){
      int l=i+1,r=n-1;
      int lastIdx=-1;
      while(l<=r){
          int mid=l+(r-l)/2;
          if(arr[mid]<tr){
              lastIdx=mid;
              l=mid+1;
          }
          else r=mid-1;
      }
      return lastIdx;
  }
    vector<int> farMin(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>suffix_min(n,INT_MAX);
        vector<int>result(n);
        suffix_min[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)suffix_min[i]=min(suffix_min[i+1],arr[i]);
        for(int i=0;i<n;i++){
            int lastIdx=last_occurence(n,suffix_min,arr[i],i);
            result[i]=lastIdx;
        }
        return result;
    }
};


// Time Complexity
// Building suffix_min
// Runs in O(n).
// For each index i, call last_occurence
// last_occurence does a binary search over suffix_min[i+1...n-1].
// Binary search takes O(log n).
// This is done for all n elements → O(n log n).
// Total Time = O(n) + O(n log n) = O(n log n)

// Space Complexity
// suffix_min array → O(n)
// result array → O(n)
// Binary search uses O(1) extra space.
// Total Space = O(n) + O(n) + O(1) = O(n)
