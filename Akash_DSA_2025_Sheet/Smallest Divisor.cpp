


class Solution {
  public:
  bool isPossible(int n,vector<int>&nums,int mid,int k){
      int count=0;
      for(int &num:nums){
          count+=(num+mid-1)/mid;
          if(count>k)return false;
      }
      return true;
  }
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int n=arr.size();
        int l=1;
        int r=*max_element(arr.begin(),arr.end());
        int smallest_divisor=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(n,arr,mid,k)){
                smallest_divisor=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return smallest_divisor;
    }
};


