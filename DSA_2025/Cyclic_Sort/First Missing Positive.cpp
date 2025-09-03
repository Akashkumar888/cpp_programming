
class Solution {
public:
// void cyclicSort(vector<int>& nums) {
//     int i = 0;
//      int n = nums.size();
//     while (i < n) {
//         int correctIndex = nums[i] - 1;
//         if (nums[i] != nums[correctIndex]) {
//             swap(nums[i], nums[correctIndex]);
//         } else {
//             i++;
//         }
//     }
// }
// Crashes for invalid index access if nums[i] is negative, 0, or > n.
// No boundary checks → can cause runtime errors like:

// void cyclicSort(vector<int>& nums) {
//         int i = 0;
//         int n = nums.size();
//         while (i < n) {
//             int correctIndex = nums[i] - 1;
//             // Check bounds and duplicates
              // if already 1 to n hai to thik otherwise only choose 1 to n number valid
//             if (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[correctIndex]) {
//                 swap(nums[i], nums[correctIndex]);
//             } else {
//                 i++;
//             }
//         }
//     }
// ✔ This is safe, but a bit less clean than the third version. It's good too, but repeating nums[i] can cause extra evaluations and is slightly harder to read.

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
    // We also check nums[i] != nums[val - 1] to avoid infinite swapping of duplicates.
//Handles only positive integers in range [1, n] → avoids index out of bound or negative indexing.
//Avoids unnecessary swaps when the element is already in the correct position or out of range.
//Prevents infinite loops by skipping values that don't need to be placed.
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        cyclicSort(nums);
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1)return i+1;
        }
        return n+1;
    }
};

