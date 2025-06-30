


class Solution {
  public:
  // binary search approach on the answer:
  bool isPossible(int n,vector<int>&arr,int mid,int k,int w){
    //   Whenever you water a flower its height increases by 1 unit.
    // that why here use difference array technique 
    //✅ diff[] is used for efficient range updates in O(1) time.
    vector<int>diff(n+1,0);  // difference array to track water added
    int totalWaterUsed=0;
    int water=0; // current water effect at position i

    for(int i=0;i<n;i++){
        water+=diff[i];  // update current water at i
        int currentHeight=arr[i]+water;

        if(currentHeight<mid){
            int need=mid-currentHeight;
            totalWaterUsed+=need;
            if(totalWaterUsed>k)return false;
            
            water+=need;               // apply water from i
            diff[i]+=need;
            if (i+w<n)diff[i+w]-=need; // stop water effect after w positions
        }
    }
    return true;
  }
    int maxMinHeight(vector<int> &arr, int k, int w) {
        // code here
        int n=arr.size();
        int l=*min_element(arr.begin(),arr.end());
        int r=*max_element(arr.begin(),arr.end());
        r+=k;
        int maxHeight=l;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(n,arr,mid,k,w)){
                maxHeight=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return maxHeight;
    }
};



// ✅ Total Time Complexity: O(n * log(k))  →  Efficient enough for large `n` (up to 1e5)

// ✅ Space Complexity: O(n)  → for the difference array


