
class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<string>ans;
        for(int &num:arr)ans.push_back(to_string(num));
        auto lambda=[&](string s1,string s2){
          return s1+s2>s2+s1;
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


// Time Complexity:
// Sorting dominates: each comparator call compares s1+s2 vs s2+s1, which is O(k) where k is the max number of digits per number (string length).
// Sort is O(n log n) comparisons ⇒ overall O(n log n · k).
// (With typical 32-bit ints, k ≤ 10.)

// Space Complexity:
// Converting all numbers to strings: O(n · k).
// Result string also up to O(n · k).
// Sort’s auxiliary space is O(log n) (for recursion/stack).
// Net: O(n · k).