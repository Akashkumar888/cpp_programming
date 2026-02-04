
class Solution {
public:
// count subarrays where max element <= bound
// 🧠 Why this works (short interview explanation)
// countSubarrays(nums, right) → all subarrays where max ≤ right
// countSubarrays(nums, left-1) → all subarrays where max < left
// Subtracting gives subarrays where
// left ≤ max ≤ right

    int countSubarrays(vector<int>& nums, int bound) {
        int count = 0, len = 0;
        for (int &x : nums) {
            if (x <= bound) {
                len++;           // extend window
            } 
            else {
                len = 0;         // break window
            }
            count += len;
        }
        return count;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return countSubarrays(nums, right) - countSubarrays(nums, left - 1);
    }
};


// 🔹 For MAXIMUM in subarray
// Core helper
// countMax(≤ X) = number of subarrays whose maximum ≤ X

// Ranges using MAX
// Required Range	Formula
// [L, R]	countMax(≤ R) - countMax(< L)
// (L, R]	countMax(≤ R) - countMax(≤ L)
// [L, R)	countMax(< R) - countMax(< L)
// (L, R)	countMax(< R) - countMax(≤ L)

// Note:
// countMax(< X) = countMax(≤ X-1)

// Helper code (MAX ≤ bound)
// int countMaxLE(vector<int>& nums, int bound) {
//     int len = 0, ans = 0;
//     for (int x : nums) {
//         if (x <= bound) len++;
//         else len = 0;
//         ans += len;
//     }
//     return ans;
// }

// 🔹 For MINIMUM in subarray
// Core helper
// countMin(≥ X) = number of subarrays whose minimum ≥ X

// Ranges using MIN
// Required Range	Formula
// [L, R]	countMin(≥ L) - countMin(> R)
// [L, R)	countMin(≥ L) - countMin(≥ R)
// (L, R]	countMin(> L) - countMin(> R)
// (L, R)	countMin(> L) - countMin(≥ R)

// Note:
// countMin(> X) = countMin(≥ X+1)

// Helper code (MIN ≥ bound)
// int countMinGE(vector<int>& nums, int bound) {
//     int len = 0, ans = 0;
//     for (int x : nums) {
//         if (x >= bound) len++;
//         else len = 0;
//         ans += len;
//     }
//     return ans;
// }

// 🔹 Example (MAX in [L, R])
// int numSubarrayBoundedMax(vector<int>& nums, int L, int R) {
//     return countMaxLE(nums, R) - countMaxLE(nums, L - 1);
// }

// 🔹 Example (MIN in [L, R])
// int numSubarrayBoundedMin(vector<int>& nums, int L, int R) {
//     return countMinGE(nums, L) - countMinGE(nums, R + 1);
// }

// 🎯 Interview one-liner
// “Convert range queries on max/min into difference of prefix-style counts using ≤ or ≥ conditions.”