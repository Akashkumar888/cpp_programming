
class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        // lowerbound r me condition arr[mid]>=k idx=mid r=mid-1
        // upperbound l me condition arr[mid]<=k idx=mid l=mid+1
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
// lower_bound logic:
// if arr[mid] >= k → idx = mid, move r = mid - 1
// else → move l = mid + 1

// lower_bound logic:
// if arr[mid] >= k → idx = mid, move r = mid - 1
// else (arr[mid] < k) → move l = mid + 1

// upper_bound logic:
// if arr[mid] > k → idx = mid, move r = mid - 1
// else → move l = mid + 1


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

