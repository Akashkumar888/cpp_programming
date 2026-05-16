
// 1️⃣ KMP (Knuth–Morris–Pratt) Algorithm

// 🔹 Idea
// KMP avoids re-checking elements by using LPS array
// (Longest Prefix which is also Suffix).

// 🔹 What is LPS?
// For each position i in pattern:
// Length of longest proper prefix
// which is also suffix ending at i.

// Example:
// Pattern = [1,2,1,2]
// LPS = [0,0,1,2]

// 🔹 How KMP Works
// 1. Build LPS array for pattern b[]
// 2. Compare pattern with array a[]
// 3. If match -> move both pointers
// 4. If mismatch -> shift using LPS
//    instead of restarting from beginning

// 🔹 Time Complexity
// O(n + m)

// 🔹 Space Complexity
// O(m)

// 🔹 Used In
// ✔️ Pattern matching
// ✔️ Subarray search
// ✔️ String searching
// ✔️ DNA matching
// ✔️ Search engines

class Solution {
  public:
    // Build LPS array
    void KMP(vector<int> &b,vector<int> &lps){
        int pre = 0;
        int suf = 1;
        while(suf < b.size()){
            // match
            if(b[pre] == b[suf]){
                lps[suf] = pre + 1;
                pre++;
                suf++;
            }
            else{
                // restart matching
                if(pre == 0){
                    lps[suf] = 0;
                    suf++;
                }
                else{
                    pre = lps[pre - 1];
                }
            }
        }
    }
    vector<int> search(vector<int> &a,vector<int> &b) {
        int n = a.size();
        int m = b.size();
        vector<int> result;
        // build LPS array
        vector<int> lps(m, 0);
        KMP(b, lps);
        int i = 0;
        int j = 0;
        while(i < n){
            // match found
            if(a[i] == b[j]){
                i++;
                j++;
            }
            // complete pattern matched
            if(j == m){
                result.push_back(i - j);
                // continue searching
                j = lps[j - 1];
            }
            // mismatch
            else if(i < n && a[i] != b[j]){
                if(j == 0){
                    i++;
                }
                else{
                    j = lps[j - 1];
                }
            }
        }
        return result;
    }
};