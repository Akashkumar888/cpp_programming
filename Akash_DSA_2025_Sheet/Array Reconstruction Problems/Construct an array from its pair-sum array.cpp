
class Solution {
  public:
// sum of all pairs in ordered form, i.e., arr[0] is sum of res[0] and res[1],
// arr[1] is sum of res[0] and res[2] and so on.
// If the size of original array res[] is n, then the size of pair-sum array arr[] would be n * (n -1) /2. 
// ✔ Step 1: It solves the first 3 equations to find a
// ✔ Step 2: Uses the first row of pair sums to compute b, c, d, …
// ✔ Step 3: This reconstruction always produces a valid array
// ✔ Step 4: GFG only checks if reconstruction is valid (not unique)
    vector<int> constructArr(vector<int>& arr) {
        // code here
        int m=arr.size();
        // m = size of pair-sum array
        // If original array has size n, then:
        // total number of pair sums = n * (n - 1) / 2
        // => m = n*(n-1)/2
        //
        // Solve this quadratic equation for n:
        // n^2 - n - 2m = 0
        // Using quadratic formula:
        // n = (1 + sqrt(1 + 8m)) / 2

        int n = (1 + sqrt(1 + 8 * m)) / 2;

        // Now we know the size of the original array
        vector<int> result(n);

        // ------------------------------------------------
        // Pair-sum structure (for original array: [a, b, c, d, ...])
        //
        // arr[0] = a + b
        // arr[1] = a + c
        // arr[2] = a + d   (if n >= 4)
        // ...
        // arr[n-1] = b + c    <-- IMPORTANT!
        //
        // First 3 equations we use:
        // a + b = arr[0]
        // a + c = arr[1]
        // b + c = arr[n-1]
        //
        // Adding first two equations:
        // (a+b) + (a+c) = 2a + (b+c)
        //
        // Substitute (b+c) from arr[n-1]:
        // arr[0] + arr[1] = 2a + arr[n-1]
        //
        // Solve for a:
        // 2a = arr[0] + arr[1] - arr[n-1]
        // a = (arr[0] + arr[1] - arr[n-1]) / 2
        // ------------------------------------------------
        
        // res[0]+res[1]=arr[0]
        // res[0]+res[2]=arr[1]
        // res[1]+res[2]=arr[n-1]
        result[0] = (arr[0] + arr[1] - arr[n - 1]) / 2;

        // ------------------------------------------------
        // Now compute remaining res[i]
        //
        // arr[i-1] = res[0] + res[i]
        // => res[i] = arr[i-1] - res[0]
        //
        // This works because the first (n-1) elements
        // of pair-sum array always represent:
        // a+b, a+c, a+d, ...
        // ------------------------------------------------
        for (int i = 1; i < n; i++) {
            result[i] = arr[i - 1] - result[0];
        }
        return result;
    }
};

// Topic: Array Reconstruction using Pairwise Sums , ✔ Array Reconstruction / Reverse Engineering of Arrays
// 🔹 Concepts: Math, Pair Sums, Observation, Deduction
// 🔹 Difficulty: Easy–Medium
// 🔹 Type: Logical + Algebraic Reconstruction Problem

// Detailed Explanation of the sqrt() Formula
// The pair-sum array size is:
// m = n*(n-1)/2
// Multiply both sides by 2:
// 2m = n*(n-1)
// Expand:
// n^2 - n - 2m = 0
// This is a quadratic equation of form:
// ax² + bx + c = 0
// Where:
// a = 1
// b = -1
// c = -2m
// Using quadratic formula:
// n = ( -b + sqrt(b^2 - 4ac ) ) / 2a
// Substitute:
// n = (1 + sqrt(1 + 8m)) / 2
// This gives the size of the original array.