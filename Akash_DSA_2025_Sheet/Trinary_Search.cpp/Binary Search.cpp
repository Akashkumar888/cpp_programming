
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        
        while (l <= r) {
            int mid1 = l + (r - l) / 3;
            int mid2 = r - (r - l) / 3;

            // Case 1: target found at mid1
            if (nums[mid1] == target) {
                return mid1;
            }

            // Case 2: target found at mid2
            if (nums[mid2] == target) {
                return mid2;
            }

            // Case 3: target is less than nums[mid1], search in left part
            if (target < nums[mid1]) {
                r = mid1 - 1;
            }

            // Case 4: target is greater than nums[mid2], search in right part
            else if (target > nums[mid2]) {
                l = mid2 + 1;
            }

            // Case 5: target lies between mid1 and mid2
            else {
                l = mid1 + 1;
                r = mid2 - 1;
            }
        }

        return -1;
    }
};

