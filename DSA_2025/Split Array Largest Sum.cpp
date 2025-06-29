
class Solution {
  public:
  bool isPossible(int n,vector<int>&arr,int mid,int k){
      int sum=0,count=1;
      for(int &num:arr){
          sum+=num;
          if(sum>mid){
              sum=num;
              count++;
          }
          if(count>k)return false;
      }
      return true;
  }
    int splitArray(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int l=*max_element(arr.begin(),arr.end()); // when n=k
        int r=accumulate(arr.begin(),arr.end(),0); // when k=1
        int maxSum=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(n,arr,mid,k)){
                maxSum=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return maxSum;
    }
};


// 🕒 Time Complexity:
// Binary Search Range: from max(arr) to sum(arr) → at most O(log(sum - max)) iterations
// Each isPossible check: O(n), where n = arr.size()
// Total Time Complexity = O(n × log(sum - max))

// 💾 Space Complexity:
// Space Complexity = O(1)

