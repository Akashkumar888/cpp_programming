
int partition(vector<int>&nums,int n){
    int l=0,r=n-1;
    while(l<r && nums[l]==nums[l+1]) l++;
    while(l<r && nums[r]==nums[r-1]) r--;
    while(l<r){
        int mid=l+(r-l)/2;
        if(nums[mid]>nums[r]) l=mid+1;
        else{
            r=mid;
        }
    }
    return r;
  }