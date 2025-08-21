
class Solution {
  public:
  //minimize the maximum number of pages 
  // binary search on answer hai 
  bool isPossible(vector<int>&arr,int k,int mid){
      int n=arr.size();
      int cnt=1;
      int sum=0;
      for(int i=0;i<n;i++){
       sum+=arr[i];
       if(sum>mid){
           sum=arr[i];
           cnt++;
       }
      }
      return cnt<=k;
  }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(n<k)return -1;
        int l=*max_element(arr.begin(),arr.end());
        int r=accumulate(arr.begin(),arr.end(),0);
        int ans=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(arr,k,mid)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
    return ans;    
    }
};

