
// 🔎 Step 1: Understand What the Question Really Asks
// We need:
// Longest subarray (i, j) such that

// sum of a1[i..j]=sum of a2[i..j]
// Both arrays are:
// Binary (0 and 1 only)
// Same size

// 🧠 Step 2: Convert the Problem (Very Important Trick)
// Instead of thinking about two arrays separately:
// Let’s create a new array:
// diff[i] = a1[i] - a2[i]
// Now the condition becomes:

// (a1[i]−a2[i])+(a1[i+1]−a2[i+1])+...+(a1[j]−a2[j])=0
// That means:
// We need the longest subarray in diff[] whose sum = 0

// 💡 Step 3: Now Problem Becomes Classic
// 👉 "Find longest subarray with sum 0"
// This is a very famous problem.

// 🚀 Step 4: How to Solve Longest Subarray with Sum 0?
// We use:
// Prefix sum
// HashMap
// Idea:
// If prefixSum becomes same at two indices,
// that means subarray between them has sum 0.
// Because:
// prefix[j] - prefix[i] = 0

class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        // code here
        int n = a1.size();
        // Step 1: Create a difference array where:
        // diff[i] = a1[i] - a2[i]
        // Goal: Find longest subarray where sum of differences is 0
        //       => a1[i..j] == a2[i..j]
        vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = a1[i] - a2[i];
        }
        unordered_map<int, int> mp; // To store (cumulative sum → first index)
        int CumSum = 0;             // Cumulative sum of the diff array
        int maxLen = 0;             // Stores length of the longest subarray

        for (int i = 0; i < n; i++) {
            CumSum += diff[i]; // Update cumulative sum

            if (CumSum == 0) {
                // Subarray from index 0 to i has equal sum in both arrays
                maxLen = i + 1;
            }
            // If this CumSum has been seen before, that means the subarray
            // between previous index+1 and current index has net sum = 0
            if (mp.find(CumSum) != mp.end()) {
                maxLen = max(maxLen, i - mp[CumSum]);
            } 
            else {
                // Store the first occurrence of this CumSum
                mp[CumSum] = i;
            }
        }
        return maxLen;
    }
};



class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        
        unordered_map<int, int> mp;  // prefixSum -> first index
        int prefixSum = 0;
        int maxLen = 0;
        
        for(int i = 0; i < n; i++) {
            prefixSum += (a1[i] - a2[i]);
            
            if(prefixSum == 0) {
                maxLen = i + 1;
            }
            
            if(mp.find(prefixSum) != mp.end()) {
                maxLen = max(maxLen, i - mp[prefixSum]);
            } else {
                mp[prefixSum] = i;
            }
        }
        
        return maxLen;
    }
};

