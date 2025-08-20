
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        int lowerbound=-1;
        while(l<=r){
        int mid=l+(r-l)/2;
        if(nums[mid]<target){
            l=mid+1;
        }
        else{
            lowerbound=mid;
            r=mid-1;
        }
        }
        return lowerbound==-1 ? n :lowerbound;
    }
};

