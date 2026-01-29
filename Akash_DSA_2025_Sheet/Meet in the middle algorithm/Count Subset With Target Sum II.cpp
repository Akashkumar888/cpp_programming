
// 🔥 Meet in the Middle (MITM) – Yaad rakhne ka Simple Trick

// Jab n ≤ 40 ho aur values negative / bahut badi ho jahan DP on sum possible na ho,
// aur brute force 2^n TLE de de — tab Meet in the Middle use karo.

// Socho:
// 2^n  = bahut bada (n = 40 → ~10^12)
// 2^(n/2) = manageable (n/2 = 20 → ~10^6)


// Isliye:

// Array ko do hisso me baant do
// Pehle half ke saare subset sums nikaalo
// Doosre half ke saare subset sums nikaalo
// Phir: firstHalfSum + secondHalfSum ≈ goal
// (binary search use karke closest ya exact match)

// 🧠 3-Step Process (Yaad rakhne ka Formula)

// Divide
// Array ko 2 halves me tod do.

// Generate
// Dono halves ke saare possible subset sums nikaalo.
// Har half ke liye 2^(n/2) sums banenge.

// Search
// Second half ko sort karo.
// Har x in firstHalf ke liye, goal - x ko secondHalf me
// lower_bound se dhundo.

// 💡 Problem Example

// LeetCode 1755 – Closest Subsequence Sum
// Target = goal

// Problem asks for:
// subset sums
// number of subsets with sum k
// closest sum to k
// knapsack-like queries with large constraints

class Solution {
  public:
  // -10^7 ≤ arr[i], k ≤ 10^7 dp nhi lagega 
  void genSums(int idx, int end, long long sum, vector<int>& arr, vector<long long>& out) {
        if(idx == end){
            out.push_back(sum);
            return;
        }
        // not pick
        genSums(idx + 1, end, sum, arr, out);
        // pick
        genSums(idx + 1, end, sum + arr[idx], arr, out);
    }

    int countSubset(vector<int> &arr, int k) {
        int n = arr.size();
        int mid = n / 2;

        vector<long long> leftSums, rightSums;

        // generate subset sums for both halves
        genSums(0, mid, 0, arr, leftSums);
        genSums(mid, n, 0, arr, rightSums);

        // sort right sums for binary search
        sort(rightSums.begin(), rightSums.end());

        long long ans = 0;
        for(long long x : leftSums){
            long long need = k - x;
            // count occurrences of 'need' in rightSums
            auto range = equal_range(rightSums.begin(), rightSums.end(), need);
            ans += (range.second - range.first);
        }

        return ans;
    }
};

// equal_range is a STL function that gives you the full range of equal values in a sorted array.
// For a sorted array arr and a value x:
// auto p = equal_range(arr.begin(), arr.end(), x);

// p.first → iterator to the first occurrence of x
// p.second → iterator to the position just after the last x
// So the count of x is:
// p.second - p.first

// Example:
// arr = {1, 2, 2, 2, 3, 5}
// equal_range(arr, 2) → [index 1, index 4)
// count = 4 - 1 = 3

// That’s why in MITM “count subset sum” problems we use:
// auto p = equal_range(rightSums.begin(), rightSums.end(), need);
// ans += (p.second - p.first);

// It counts how many subsets in the right half have sum = need.

// Yes, but one lower_bound is not enough for counting.
// You need two binary searches:

// int l = lower_bound(arr.begin(), arr.end(), need) - arr.begin();
// int r = lower_bound(arr.begin(), arr.end(), need + 1) - arr.begin();
// count = r - l;

class Solution {
public:
    void genSums(int idx, int end, long long sum,
                 vector<int>& arr, vector<long long>& out) {
        if (idx == end) {
            out.push_back(sum);
            return;
        }
        genSums(idx + 1, end, sum, arr, out);            // not pick
        genSums(idx + 1, end, sum + arr[idx], arr, out); // pick
    }

    // own lower_bound: first index where arr[i] >= target
    int lowerBound(vector<long long>& arr, long long target) {
        int l = 0, r = arr.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }

    int countSubset(vector<int> &arr, int k) {
        int n = arr.size();
        int mid = n / 2;

        vector<long long> leftSums, rightSums;
        genSums(0, mid, 0, arr, leftSums);
        genSums(mid, n, 0, arr, rightSums);

        sort(rightSums.begin(), rightSums.end());

        long long ans = 0;
        for (long long x : leftSums) {
            long long need = k - x;

            int l = lowerBound(rightSums, need);
            int r = lowerBound(rightSums, need + 1);

            ans += (r - l);   // count of `need`
        }
        return ans;
    }
};
