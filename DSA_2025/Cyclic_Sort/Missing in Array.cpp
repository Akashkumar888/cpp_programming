
class Solution {
  public:
  void cyclicSort(vector<int>& nums, int n) {
        int i = 0;
        while (i < n) { // containing elements from the range 1 to n
            int val = nums[i];
            if (val >= 1 && val <= n && nums[i] != nums[val - 1]) {
                swap(nums[i], nums[val - 1]);
            } else
                i++;
        }
    }
    int missingNum(vector<int>& arr) {
        // code here
    // 1 to n (inclusive). This array represents a permutation of the integers from 1 to n with one
       int n=arr.size(); 
        cyclicSort(arr,n); 
        for(int i=0;i<n;i++){ 
            if(arr[i]!=i+1)return i+1; 
            } 
        return n+1; 
    }
};