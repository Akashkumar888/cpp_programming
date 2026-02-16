
class Solution {
public:
// jo unusual ho us pr target krna chahiye like here You are given a string s consisting only of the characters 'a', 'b', and 'c'.

    // ================= CASE-2 HELPER =================
    int helper(string &s, char ch1, char ch2) {
        int n = s.length();
        unordered_map<int,int> diffMap;
        int count1 = 0;
        int count2 = 0;
        int maxL = 0;
        for(int i = 0; i < n; i++) {
            // If character is not part of pair → reset
            if(s[i] != ch1 && s[i] != ch2) {
                diffMap.clear();
                count1 = 0;
                count2 = 0;
                continue;
            }
            if(s[i] == ch1) count1++;
            if(s[i] == ch2) count2++;
            // If equal directly
            if(count1 == count2) {
                maxL = max(maxL, count1 + count2);
            }
            int diff = count1 - count2;

            if(diffMap.count(diff)) {
                maxL = max(maxL, i - diffMap[diff]);
            }
            else {
                diffMap[diff] = i;
            }
        }
        return maxL;
    }

    int longestBalanced(string s) {
        int n = s.length();
        int maxL = 0;

        // ================= CASE-1 =================
        // Only one character like "aaaa"
        int count = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) {
                count++;
                maxL = max(maxL, count);
            }
            else {
                count = 1;
            }
        }
        
        // ================= CASE-2 =================
        maxL = max(maxL, helper(s, 'a', 'b'));
        maxL = max(maxL, helper(s, 'a', 'c'));
        maxL = max(maxL, helper(s, 'b', 'c'));

        // ================= CASE-3 =================
        int countA = 0;
        int countB = 0;
        int countC = 0;

        unordered_map<string,int> diffMap;

        for(int i = 0; i < n; i++) {

            if(s[i] == 'a') countA++;
            if(s[i] == 'b') countB++;
            if(s[i] == 'c') countC++;

            if(countA == countB && countA == countC) {
                maxL = max(maxL, countA + countB + countC);
            }

            int diffAB = countA - countB;
            int diffAC = countA - countC;

            string key = to_string(diffAB) + "_" + to_string(diffAC);

            if(diffMap.count(key)) {
                maxL = max(maxL, i - diffMap[key]);
            }
            else {
                diffMap[key] = i;
            }
        }

        return maxL;
    }
};


// ✅ When to use this prefix-difference trick
// ✅ What similar problems look like
// ✅ How to identify in interview
// ✅ Problem list you should practice
// 🧠 WHEN TO USE THIS TECHNIQUE?
// Use this pattern when problem says something like:
// “Equal frequency”
// “Balanced substring”
// “Same number of X and Y”
// “Counts are equal”
// “Difference becomes zero”
// “Longest subarray where … counts equal”

// 🔥 CORE IDEA
// If problem says:
// countA == countB
// Convert it to:
// countA - countB = 0

// Then use:
// prefix difference + hashmap
// If same difference appears again →
// substring between them is balanced.

// 🟢 CASE TYPES YOU SHOULD RECOGNIZE
// ✅ 1️⃣ Two characters equal count
// Condition:
// countA == countB
// Use:
// diff = countA - countB
// Store first index of each diff.

// 🔥 Similar Problems:
// Leetcode 525 – Contiguous Array
// Equal 0 and 1
// Leetcode 1371 – Longest Substring with Even Vowels
// Leetcode 560 – Subarray Sum Equals K (similar prefix logic)
// ✅ 2️⃣ Three characters equal count
// Condition:
// countA == countB == countC
// Convert to:
// countA - countB = 0
// countA - countC = 0

// Store:
// (diffAB , diffAC)

// Now it's 2D prefix difference.
// 🔥 Similar Problems:
// Leetcode 1124 – Longest Well Performing Interval
// Equal number of 0,1,2 in array
// GFG – Largest subarray with equal 0,1,2
// Variants of balanced substring with 3 characters

// ✅ 3️⃣ General K characters equal frequency
// For k characters:
// You need (k-1) differences.
// Example 4 characters:
// Store:
// (a-b, a-c, a-d)
// This becomes multidimensional prefix trick.
// 🚀 HOW TO IDENTIFY IN INTERVIEW
// If interviewer says:
// Longest substring
// Equal frequency
// Balanced
// Same count
// Equal occurrences
// Immediately think:
// prefix difference + hashmap
// 🧩 HOW TO APPROACH SUCH PROBLEMS
// Step 1: Convert equality to difference form
// Example:
// countA == countB
// → countA - countB = 0
// Step 2: Think Prefix
// Let:
// prefix[i] = count difference till i
// If same prefix diff appears twice →
// middle substring is balanced.

// Step 3: Store first occurrence only
// Why?
// Because we want longest substring.

