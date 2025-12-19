
class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        // lowerbound r me condition idx=mid r=mid-1
        // upperbound l me condition idx=mid l=mid+1
        int l=0,r=n-1;
        int idx=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]>=k){
                idx=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return idx;
    }
};


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

