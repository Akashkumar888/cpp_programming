
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
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // 1️⃣ find breakpoint
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // 2️⃣ if breakpoint exists
        if (i >= 0) {
            int j = n - 1;
            while (nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }

        // 3️⃣ reverse right part
        reverse(nums.begin() + i + 1, nums.end());
    }
};


#include <bits/stdc++.h>

using namespace std;

void nextPermutation(vector<int>& nums) {
    // Write your code here
    // next_permutation(nums.begin(),nums.end());
    int n=nums.size();
    int i=n-1;
    while(i>0 && nums[i-1]>=nums[i])i--;
    if(i>0){
    int j=n-1;
    while(j>i && nums[i-1]>=nums[j])j--;
    swap(nums[i-1],nums[j]);
    }
    // sort from index i to n-1 index
    sort(nums.begin()+i,nums.end());
}


#include <bits/stdc++.h>

using namespace std;

void nextPermutation(vector<int>& nums) {
    // Write your code here
    // next_permutation(nums.begin(),nums.end());
    int n=nums.size();
    int i=n-2;
    while(i>=0 && nums[i]>=nums[i+1])i--;
    if(i>=0){
    int j=n-1;
    while(j>i && nums[i]>=nums[j])j--;
    swap(nums[i],nums[j]);
    }
    // sort from index i+1 to n-1 index
    sort(nums.begin()+i+1,nums.end());
}