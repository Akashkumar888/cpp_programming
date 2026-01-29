
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2,nums1); // ensure a is smaller
        int m=nums1.size();
        int n=nums2.size();
            int low = 0, high = m;
        
            while (low <= high) {
                int cut1 =low + (high - low) / 2;
                int cut2 = (m + n + 1) / 2 - cut1;
        
                int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
                int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
        
                int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];
                int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];
        
                if (l1 <= r2 && l2 <= r1){
                    if ((m + n) % 2 == 0) return (max(l1, l2) + min(r1, r2)) / 2.0;
                    else return max(l1, l2);
                } 
                else if (l1 > r2) {
                    high = cut1 - 1;
                } 
                else {
                    low = cut1 + 1;
                }
    }
    return -1; 
    }
};

// 🔍 THREE TYPES OF BINARY SEARCH (MASTER BLUEPRINT)
// 1️⃣ Simple Binary Search (Search on Index)
// 2️⃣ Binary Search on Answer (Search on Value)
// 3️⃣ Partition / Condition-based Binary Search (Your hard ones)

// Once you see the decision condition, the pattern becomes obvious.

// 1️⃣ SIMPLE BINARY SEARCH
// 👉 “Is this exact value present?”
// 🔹 When to use

// Sorted array

// You know what value you are looking for

// Move left / right based on comparison

// 🔹 Core Question

// “Is arr[mid] == target ?”

// 🔹 Template
// int l = 0, r = n - 1;
// while(l <= r){
//     int mid = l + (r - l) / 2;
//     if(arr[mid] == target) return mid;
//     else if(arr[mid] < target) l = mid + 1;
//     else r = mid - 1;
// }

// 🔹 Examples

// Search in sorted array

// Lower bound / upper bound

// Count ≤ x in sorted row (used inside matrix median)

// 📌 Your code using this

// countSmallerEqual(mat[i], mid)


// This is pure simple binary search.

// 2️⃣ BINARY SEARCH ON ANSWER
// 👉 “What is the minimum / maximum value that satisfies a condition?”
// 🔹 When to use

// Answer lies in a range

// You can check feasibility

// Condition is monotonic

// 🔹 Core Question

// “Is this value POSSIBLE?”

// 🔹 Mental Signal 🚨

// Words like:
// minimum, maximum, median, capacity, time, pages

// 🔹 Template
// int l = minValue, r = maxValue;
// while(l < r){
//     int mid = l + (r - l) / 2;
//     if(isPossible(mid)) r = mid;
//     else l = mid + 1;
// }
// return l;

// 🔹 Your Example: Median of Row-wise Sorted Matrix
// 🔍 Observation

// Median is a value, not index

// Value range = min element → max element

// Condition:

// “How many numbers ≤ mid?”

// 🔹 Mapping
// if(count < k) mini = mid + 1;
// else maxi = mid;


// ✔ This is Binary Search on Answer

// 3️⃣ PARTITION / CONDITION-BASED BINARY SEARCH
// 👉 “Find a point where LEFT condition and RIGHT condition both hold”

// 🔥 This is the hardest but most powerful

// 🔹 When to use

// Two sorted structures

// Need k-th element / median / peak

// No direct index

// Decision depends on neighbour comparisons

// 🔹 Core Question

// “Is this partition valid?”

// 🔑 GOLDEN RULE (Very Important)

// Whenever you see:

// l1 <= r2 && l2 <= r1


// 💥 THIS IS PARTITION BINARY SEARCH

// 📌 Example 1: k-th Element of Two Sorted Arrays
// 🔹 What are we doing?

// Taking mid1 elements from a

// Taking k - mid1 from b

// Checking if partition is valid

// 🔹 Why Binary Search?

// Because as mid1 increases:

// l1 increases

// r2 decreases
// ➡️ Monotonic condition

// 🔹 Direction logic
// if(l1 > r2) → take fewer from a → move left
// else → take more from a → move right


// ✔ Partition Binary Search

// 📌 Example 2: Median of Two Sorted Arrays

// Same idea, only:

// k = (m+n+1)/2


// Everything else identical.

// 📌 Example 3: Peak in 2D Grid
// 🔹 Observation

// We binary search columns

// For each column → find max row

// Compare left & right

// 🔹 Core Decision
// if(right > curr) move right
// else move left


// ✔ Binary Search on Direction
// ✔ Still condition-based

// 🧠 HOW TO IDENTIFY WHICH BINARY SEARCH TO USE
// Ask these questions 👇
// Question	If YES →
// Searching exact element?	Simple BS
// Answer is min/max value?	BS on Answer
// Partition / median / kth?	Partition BS
// Condition changes direction?	Condition-based BS
// 🧩 ONE-LINE MEMORY TRICK

// ❝ Binary Search is not about arrays — it’s about monotonic decisions ❞