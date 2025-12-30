

class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        // Your code goes here
        int n = a.size();
    int low = 0, high = n;

    while (low <= high) {
        int cut1 =low + (high - low) / 2;            // partition in array a
        int cut2 = n - cut1;                    // remaining partition in array b

        int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];

        int r1 = (cut1 == n) ? INT_MAX : a[cut1];
        int r2 = (cut2 == n) ? INT_MAX : b[cut2];

        if (l1 <= r2 && l2 <= r1) {
            return (max(l1, l2) + min(r1, r2)) / 2.0;
        } 
        else if (l1 > r2) {
            high = cut1 - 1;
        } 
        else {
            low = cut1 + 1;
        }
    }
    return -1; // Should never reach here
    }
};


// 🔑 Big Idea (Very Important)
// Binary Search is NOT only for arrays.
// You can binary-search on:
// Index (normal BS)
// Answer space (value)
// Partition point (most powerful)
// All your examples fall into 2 or 3.

// 🧠 Step 1: Start from SIMPLE Binary Search
// Classic BS template
// while(l <= r){
//     mid = l + (r-l)/2;
//     if(condition(mid)) r = mid-1;
//     else l = mid+1;
// }
// 🔹 Ask ONE question only:
// “If mid is my guess, can I decide LEFT or RIGHT?”
// If yes → Binary Search possible.
// 🧩 Pattern 1: Binary Search on PARTITION
// (Used in kthElement, median of 2 arrays)
// 🔸 Problem type
// Two sorted arrays
// Find:
// k-th element
// median
// No merging allowed
// 🧠 Key Observation
// If we split arrays like this:
// LEFT PART | RIGHT PART
// And:
// max(left part) <= min(right part)
// 👉 Then partition is valid
// 🔍 How your brain should think
// Instead of searching value, search:
// “How many elements to take from array A?”
// That number = cut1
// 🔹 kthElement Logic
// cut1 = elements taken from A
// cut2 = k - cut1 (from B)
// Check:
// l1 <= r2 && l2 <= r1
// If:
// l1 > r2 → took too many from A → go LEFT
// l2 > r1 → took too few from A → go RIGHT
// 🔥 This is binary search on partition size
// 🧠 Same idea → Median of Two Sorted Arrays
// Only change:
// cut2 = (m+n+1)/2 - cut1
// And answer depends on:
// odd → max(l1,l2)
// even → (max(l1,l2)+min(r1,r2))/2
// 📌 When to use PARTITION BS?
// ✅ When:
// Arrays are sorted
// You’re asked k-th / median
// Merging is too slow
// 🧩 Pattern 2: Binary Search on ANSWER (Value)
// (Used in matrix median)
// 🔸 Problem type
// Matrix rows are sorted
// Find median
// You cannot flatten
// 🧠 Key Observation
// Median is a value, not an index.
// So binary search on:
// [min value ... max value]
// 🔍 Check function
// For a guessed value mid:
// “How many elements ≤ mid?”
// If:
// count < k → answer is bigger
// count >= k → answer may be mid or smaller
// 🔑 That’s why:
// while(mini < maxi)
// Not <=
// And:
// if(count < k) mini = mid + 1;
// else maxi = mid;
// 🔥 This is value-based binary search
// 📌 When to use VALUE BS?
// ✅ When:
// Answer lies in numeric range
// You can check count / feasibility for a guess
// 🧩 Pattern 3: Binary Search on COLUMN
// (2D Peak Element)
// 🔸 Problem type
// 2D matrix
// Need a peak
// No sorting row-wise or column-wise
// 🧠 Key Observation
// You don’t need full search.
// Only compare left & right columns.
// Steps:
// Pick middle column
// Find max in that column
// Compare left & right neighbors
// Move toward larger side
// 🔥 Why BS works?
// Because:
// There is guaranteed to be a peak
// And gradient tells direction.
// 📌 When to use this?
// ✅ When:
// 2D grid
// Peak / local maxima
// Neighbors decide direction
// 🧩 Pattern 4: Binary Search on COUNT
// (countSmallerEqual)
// This is helper BS.
// return l;
// Why?
// l ends at first index > val
// So l = count of elements ≤ val
// Used inside:
// matrix median
// kth smallest
// range queries

// 🧠 Master Decision Table
// Problem asks	Binary Search on
// Find index	Index
// Find kth / median in 2 sorted arrays	Partition
// Median in sorted matrix	Value
// Peak in 2D	Column
// Count ≤ x	Index
// 🔑 Final Mental Formula (Memorize This)
// Whenever you see a problem:
// 1️⃣ Ask: Is array sorted / monotonic?
// 2️⃣ Ask: Can I check left or right from a guess?
// 3️⃣ Decide BS type:
// Index
// Value
// Partition

// 🚀 Next Level Practice (Highly Recommended)
// Kth smallest in sorted matrix
// Allocate minimum pages
// Aggressive cows
// Painters partition
// Book allocation
// (All same logic, different clothes)