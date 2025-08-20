
class Solution {
public:
int partition(vector<int>&nums){
    int l=0,r=nums.size()-1;
    while(l<r){
        int mid=l+(r-l)/2;
        if(nums[mid]>nums[r])l=mid+1;
        else{
            r=mid;
        }
    }
    return r;
}
int binarySearch(int l,int r,vector<int>&nums,int tr){
    while(l<=r){
        int mid=l+(r-l)/2;
        if(nums[mid]==tr)return mid;
        else if(nums[mid]<tr)l=mid+1;
        else if(nums[mid]>tr)r=mid-1;
    }
    return -1;
}
int search(vector<int>& nums, int target) {
    int n=nums.size();
    int  pivot_idx=partition(nums);
    int idx=binarySearch(0,pivot_idx-1,nums,target);
    if(idx!=-1){
    return idx;
    }
    idx=binarySearch(pivot_idx,n-1,nums,target);
    return idx;
    }
};