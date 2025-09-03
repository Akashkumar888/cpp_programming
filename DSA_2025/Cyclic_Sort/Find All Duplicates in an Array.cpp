
class Solution {
public:
void cyclicSort(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int val = nums[i];
            // if already 1 to n hai to thik otherwise only choose 1 to n number valid
            if (val >= 1 && val <= n && nums[i] != nums[val - 1]) {
    // Only place nums[i] if it lies within [1, n] and is not already in correct place
                swap(nums[i], nums[val - 1]);
            } else {
                i++;
            }
        }
    }
    vector<int> findDuplicates(vector<int>& nums) {
        //  nums are in the range [1, n]
        // then use cyclic sort
        vector<int>ans;
        int n=nums.size();
        cyclicSort(nums);
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1)ans.push_back(nums[i]);
        }
        return ans;
    }
};







class Solution {
  public:
  void cyclicSort(vector<int>&nums,int n){
      int i=0;
      while(i<n){
        //   containing elements from the range 1 to n
        int val=nums[i];
        if(val>=1 && val<=n && nums[i]!=nums[val-1]){
            swap(nums[i],nums[val-1]);
        }
        else i++;
      }
  }
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        int n=arr.size();
        cyclicSort(arr,n);
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1)ans.push_back(arr[i]);
        }
        return ans;
    }
};

// Cyclic sort is super efficient when the numbers are supposed to be in the range [1, n] or [0, n-1]. Examples include:
