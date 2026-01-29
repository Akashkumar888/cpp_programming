
// User function Template for C++

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
    vector<int> sortArray(vector<int>& arr) {
        // distinct integers from 1 to n
        int n=arr.size(); 
        cyclicSort(arr,n); 
        return arr;
    }
};