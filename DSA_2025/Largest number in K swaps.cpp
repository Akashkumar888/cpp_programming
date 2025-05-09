
class Solution {
  public:
    // Function to find the largest number after k swaps.
string solve(int n,int k,string &s){
    if (k == 0) {
        return s;
    }
    string ans = s;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] < s[j]) {
                swap(s[i], s[j]); // do 
                ans = max(ans, solve(n,k-1,s)); // explore
                swap(s[i], s[j]); // undo
            }
        }
    }
    return ans;
}
    string findMaximumNum(string& s, int k) {
        // code here.
        int n =s.size();
        return solve(n,k,s);
    }
  };
  