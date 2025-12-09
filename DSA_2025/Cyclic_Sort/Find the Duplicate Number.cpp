
class Solution {
public:
void cyclicSort(vector<int>& nums, int n) {
        int i = 0;
        while (i < n) { // containing elements from the range 1 to n
            int val = nums[i];
            if (val >= 1 && val <= n && nums[i] != nums[val - 1]) {
                swap(nums[i], nums[val - 1]);
            } 
            else i++;
        }
    }
    int findDuplicate(vector<int>& nums) {
        // containing n + 1 integers where each integer is in the range [1, n] inclusive.
        // one repeated number in nums
        int n=nums.size(); 
        cyclicSort(nums,n); 
        for(int i=0;i<n;i++){ 
          if(nums[i]!=i+1)return nums[i]; 
        } 
        return n;
    }
};




class Solution {
public:
//Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive. 
// index overflow nhi hoga kabhi 
    int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Find intersection point using only while loop
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }

        // Phase 2: Find entrance to the cycle (duplicate number)
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow; // or fast
    }
};

