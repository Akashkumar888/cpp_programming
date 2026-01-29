
class Solution {
  public:
  bool isPossible(vector<int>&arr,int mid,int k,int m){
      int bouquets=0;
      int flowers=0;
      for(int num:arr){
          if(num<=mid){
              flowers++;
              if(flowers==k){
                  bouquets++;
                  flowers=0;
                  if(bouquets>=m)return true;
              }
          }
          else flowers=0;
      }
      return false;
  }
    int minDaysBloom(vector<int>& arr, int k, int m) {
        // Code here
        int n=arr.size();
        if(m*k>n)return -1;
        // You must not sort arr in minDaysBloom, because the order matters (bouquets need adjacent flowers).
        int l=1;// start from first day and end with last day 
        int r=*max_element(arr.begin(),arr.end());
        int minDays=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            //  minimum number of days required to make exactly m bouquets.
            if(isPossible(arr,mid,k,m)){
                minDays=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return minDays;
    }
};

// ✅ Final Complexity (after removing sort):
// Time: O(n · log(maxDay))
// Space: O(1)

