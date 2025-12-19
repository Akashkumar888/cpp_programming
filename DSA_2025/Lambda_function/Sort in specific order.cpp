
class Solution {
  public:
    void sortIt(vector<int>& arr) {

        auto cmp = [&](int a, int b) {
            // both odd → descending order
            if (a % 2 != 0 && b % 2 != 0)return a > b;

            // both even → ascending order
            if (a % 2 == 0 && b % 2 == 0)return a < b;

            // odd comes before even
            return (a % 2 != 0);
        };
        sort(arr.begin(), arr.end(), cmp);
    }
};

// All odd numbers come before even numbers
// Odd numbers are sorted in descending order
// Even numbers are sorted in ascending order

// 🧠 How the comparator (cmp) works
// auto cmp = [&](int a, int b) {
// This comparator compares two elements at a time (a and b) and decides which one should come first.
// ✅ Case 1: Both numbers are odd
// if (a % 2 != 0 && b % 2 != 0)
//     return a > b;

// If both a and b are odd
// We want descending order
// So:
// If a > b → a comes before b
// 📌 Example:
// Compare 7 and 3 → 7 > 3 → true → 7 placed first
// ✅ Case 2: Both numbers are even
// if (a % 2 == 0 && b % 2 == 0)
//     return a < b;

// If both are even
// We want ascending order
// So:
// If a < b → a comes before b
// 📌 Example:
// Compare 2 and 8 → 2 < 8 → true → 2 placed first
// ✅ Case 3: One is odd and the other is even
// return (a % 2 != 0);
// If a is odd and b is even → return true
// This forces odd numbers to come before even numbers
// 📌 Examples:
// Compare 5 and 4 → 5 is odd → true → 5 comes first
// Compare 4 and 5 → 4 is even → false → 5 comes first
// 🔁 How sort() uses this comparator
// sort() repeatedly calls cmp(a, b)
// If cmp(a, b) returns true, a is placed before b
// If it returns false, b comes first
// This process continues until all elements follow the rules.
// 📌 Final Ordering Result
// Given input:
// [1, 2, 3, 5, 4, 7, 10]

// Output:
// [7, 5, 3, 1, 2, 4, 10]

// ✔ Odds first (descending): 7 5 3 1
// ✔ Evens next (ascending): 2 4 10
// 🗣️ Interview-Ready One-Line Explanation
// “The comparator first separates odd and even numbers, sorts odd numbers in descending order, sorts even numbers in ascending order, and ensures all odds appear before evens.”
// 🔥 Key Interview Tip
// If asked why comparator is used, say:
// “Because the sorting logic depends on multiple conditions—parity and order—which cannot be handled by default sorting.”
