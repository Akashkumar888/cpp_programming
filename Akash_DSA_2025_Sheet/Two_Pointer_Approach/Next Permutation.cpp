
class Solution {
  public:
// ✅ Step-by-Step Approach (How to remember)
// 1️⃣ Find the Breakpoint
// From right to left, find the first index i such that
// nums[i] < nums[i + 1]
// 📌 This is where the increasing order breaks.
// If no such i exists → array is the largest permutation
// Just reverse the whole array and return
// “Jahan order tootega, wahi se next permutation banega”

// 2️⃣ Find Just Bigger Element
// Again from right to left, find index j such that
// nums[j] > nums[i]
// Why right?
// Because we want the smallest bigger number than nums[i].

// 3️⃣ Swap
// Swap:
// nums[i] ↔ nums[j]
// “Break ke baad thoda sa bada number lao”

// 4️⃣ Reverse the Right Part
// Reverse the subarray:
// from i+1 to end
// Because it’s already in descending order, reversing makes it the smallest possible.
    void nextPermutation(vector<int>& arr) {
        // code here
        int n = arr.size();
        int i = n - 2;

        // 1️⃣ find breakpoint
        while (i >= 0 && arr[i] >= arr[i + 1]) {
            i--;
        }

        // 2️⃣ if breakpoint exists
        if (i >= 0) {
            int j = n - 1;
            while (arr[i] >= arr[j]) {
                j--;
            }
            swap(arr[i], arr[j]);
        }

        // 3️⃣ reverse right part
        reverse(arr.begin() + i + 1, arr.end());
    }
};
