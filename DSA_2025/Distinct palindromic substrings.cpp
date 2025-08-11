
class Solution {
  public:
  bool isPalindrome(string &s){
      int i=0,j=s.size()-1;
      while(i<j){
          if(s[i]!=s[j])return false;
          i++,j--;
      }
      return true;
  }
  void solve(int start,int n,string &s,unordered_set<string>&seen,vector<string>&result){
        for (int end = start; end < n; end++) {
            string sub = s.substr(start, end - start + 1); // current substring
            if (isPalindrome(sub) && seen.find(sub) == seen.end()) {
                result.push_back(sub);
                seen.insert(sub);
            }
            solve(end + 1, n, s, seen, result); // explore further
        }
    }
    vector<string> palindromicSubstr(string &s) {
        // code here
        vector<string>result;
        int n=s.size();
        unordered_set<string>seen;
        solve(0,n,s,seen,result);
        return result;
    }
};





class Solution {
  public:
  void expandFromCenter(string &s, int left, int right, unordered_set<string> &seen) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            if (right - left + 1 >= 1) { // allow length >= 1
                seen.insert(s.substr(left, right - left + 1));// generate all but it sote unique because it is set 
            }
            left--;
            right++;
        }
    }
    vector<string> palindromicSubstr(string &s) {
        // code here
       unordered_set<string> seen;
        int n = s.size();

        for (int center = 0; center < n; center++) {
            // Odd length palindromes
            expandFromCenter(s, center, center, seen);
            // Even length palindromes
            expandFromCenter(s, center, center + 1, seen);
        }

        return vector<string>(seen.begin(), seen.end());
    }
};
