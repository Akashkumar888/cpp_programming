
class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<string>ans;
        for(int &num:arr)ans.push_back(to_string(num));
        auto lambda=[&](string s1,string s2){
          return s1+s2>s2+s1;// place s1 before s2 if s1+s2 is lexicographically larger
        };
        sort(ans.begin(),ans.end(),lambda);
        string result="";
        for(string &str:ans)result+=str;
        while (result.size() > 1 && result[0] == '0') {
            result.erase(0, 1); // erase first character
        }
        return result;
    }
};

// This means: put s1 before s2 when concatenating s1 then s2 gives a bigger number than s2 then s1.
// Step-by-step (key pair comparisons)
// Start as strings: ["3","30","34","5","9"].
// I’ll simulate insertion sort (deterministic and easy to follow). start:
// ["3","30","34","5","9"]

// Step 0 — Initial
// Sorted portion: ["3"]
// Unprocessed: ["30","34","5","9"]
// Full: ["3","30","34","5","9"]

// Step 1 — Insert "30" into sorted ["3"]
// Compare comp("30","3") → "303" vs "330" → false → "30" goes after "3" (no change)
// Sorted: ["3","30"]
// Full: ["3","30","34","5","9"]

// Step 2 — Insert "34" into sorted ["3","30"]
// Compare comp("34","30") → "3430" vs "3034" → true → "34" should come before "30"
// Now compare comp("34","3") → "343" vs "334" → true → "34" should come before "3"
// After inserting "34" in correct place:
// Sorted: ["34","3","30"]
// Full: ["34","3","30","5","9"]

// Step 3 — Insert "5" into sorted ["34","3","30"]
// Compare comp("5","30") → "530" vs "305" → true → move before "30"
// Compare comp("5","3") → "53" vs "35" → true → move before "3"
// Compare comp("5","34") → "534" vs "345" → true → move before "34"
// After inserting "5":
// Sorted: ["5","34","3","30"]
// Full: ["5","34","3","30","9"]

// Step 4 — Insert "9" into sorted ["5","34","3","30"]
// Compare comp("9","30") → "930" vs "309" → true
// Compare comp("9","3") → "93" vs "39" → true
// Compare comp("9","34") → "934" vs "349" → true
// Compare comp("9","5") → "95" vs "59" → true

// After inserting "9" at front:
// Sorted: ["9","5","34","3","30"]
// Full (final): ["9","5","34","3","30"]

// Final concatenation
// Concatenate in order → "9" + "5" + "34" + "3" + "30" = "9534330"

// Time Complexity:
// Sorting dominates: each comparator call compares s1+s2 vs s2+s1, which is O(k) where k is the max number of digits per number (string length).
// Sort is O(n log n) comparisons ⇒ overall O(n log n · k).
// (With typical 32-bit ints, k ≤ 10.)

// Space Complexity:
// Converting all numbers to strings: O(n · k).
// Result string also up to O(n · k).
// Sort’s auxiliary space is O(log n) (for recursion/stack).
// Net: O(n · k).
