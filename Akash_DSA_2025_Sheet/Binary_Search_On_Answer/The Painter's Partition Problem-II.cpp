
class Solution {
  public:
  bool isPossible(int n,vector<int>&arr,int k,int mid){
      int count=1;// suruat me ek painter to chahiye hi na 
      int sum=0;
      for(int i=0;i<n;i++){
          sum+=arr[i];
          if(sum>mid){
              sum=arr[i];// contiguous sequence of boards (no skipping or splitting allowed).
              count++;
          }
          if(count>k)return false;// jitna painter chahiye usse jyada lg raha tb false 
      }
      return true;
  }
    int minTime(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int l=*max_element(arr.begin(),arr.end());// ek painter to sabse jyada time vala kaam kr lega 
        int r=accumulate(arr.begin(),arr.end(),0);
        int minAmountOfTime=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(n,arr,k,mid)){
                minAmountOfTime=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return minAmountOfTime;
    }
};

