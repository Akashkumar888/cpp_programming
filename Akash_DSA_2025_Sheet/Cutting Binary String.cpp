class Solution {
    public:
    bool isPowerOfFive(int num) {
        if (num == 0) return false;
        while (num % 5 == 0) num /= 5;
        return num == 1;
    }
    int solve(int i, int n, string &s, vector<int> &dp) {
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];
        int minCount = n + 1;
        int num = 0;
        for (int j = i; j < n; j++) {
            num = (num << 1) + (s[j] - '0');  // build full binary number
            if (s[i] == '1' && isPowerOfFive(num)) {
                minCount = min(minCount, 1 + solve(j + 1, n, s, dp));
            }
        }
        return dp[i] = minCount;
    }
    
    int cuts(string s) {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        int ans = solve(0, n, s, dp);
        return ans > n ? -1 : ans;
    }
};

// ✅ Version 1: Top-down DP + isPowerOfFive() inside the loop
// 🔹 Time Complexity:
// For each index i, you try all j from i to n-1. So total substrings = O(n²).
// For each substring, isPowerOfFive() is called.
// It divides by 5 repeatedly, so it runs in O(log(num)) time.
// Since num is binary and can be up to ~2³¹ (1e9), log(num) ≈ 30.
// Final time = O(n² * log(num)) ≈ O(n² * 30) → O(n²) in practice.
// 🔹 Space Complexity:
// A dp array of size n+1 → O(n)
// Recursion stack depth up to n → O(n)
// Final space = O(n)


class Solution {
  public:
  int solve(int i,int n,string &s,unordered_set<int>&st,vector<int>&dp){
      if(i==n){
          return 0;
      }
      if(dp[i]!=-1)return dp[i];
      int minCount=n+1;
      int num=0;
      for(int j=i;j<n;j++){
        // num= num* 2 + (s[j]-'0');
        num=(num<<1) + (s[j]-'0');
          if(s[i]=='1' && st.count(num)){
              minCount=min(minCount,1+solve(j+1,n,s,st,dp));
          }
      }
      return dp[i] =minCount;
  }
    int cuts(string s) {
        // code here
        int n=s.size();
        unordered_set<int>st;
        vector<int>dp(n+1,-1);
        for(int num=1;num<=1e9;num=num*5)st.insert(num);
        if(s[0]=='0')return -1;
        int ans= solve(0,n,s,st,dp);
        return ans>n?-1:ans;
    }
};

// ✅ Version 2: Top-down DP + Precomputed unordered_set of powers of 5
// 🔹 Time Complexity:
// Again, all substrings are tried → O(n²)
// But instead of checking isPowerOfFive(), you use a hash set (unordered_set) for lookup
// Lookup in hash set = O(1) average.
// So overall time = O(n²)
// 🔹 Space Complexity:
// dp array → O(n)
// unordered_set of powers of 5 (at most ~14 entries: 1, 5, 25, ..., ≤1e9) → O(1)
// Recursion stack → O(n)
// Final space = O(n)

class Solution {
public:
    bool isPowerOfFive(long long num) {
        if (num == 0) return false;
        while (num % 5 == 0) num /= 5;
        return num == 1;
    }
    int cuts(string s) {
        int n = s.size();
        queue<pair<int, int>> q; // {position, split}
        q.push({0, 0});
        vector<bool>visited(n, false);

        while (!q.empty()) {
            int i= q.front().first;
            int split=q.front().second;
            q.pop();
            if (i == n) return split;
            if (visited[i]) continue;
            visited[i] = true;
            long long num = 0;
            for (int j = i; j < n; j++) {
                if (s[i] == '0') break; // leading 0 → skip
                num = (num << 1) + (s[j] - '0');
                if (isPowerOfFive(num)) {
                    q.push({j + 1,split + 1});
                }
            }
        }
        return -1; // not possible
    }
};

// ✅ Version 3: BFS (Queue based)
// 🔹 Time Complexity:
// BFS explores all valid positions where cuts can happen.
// From each index i, we can go to multiple js by checking all substrings → again O(n²)
// For each such substring, you call isPowerOfFive() (log(num)) times, same as Version 1.
// So worst case = O(n² * log(num)) ≈ O(n²) in practice
// 🔹 Space Complexity:
// visited array → O(n)
// queue stores at most n elements in worst case → O(n)
// Final space = O(n)



// Works for small integers only (e.g. within 32-bit or 64-bit int).
// To check "is power of X" → use:

bool isPowerOf(int num, int x) {
    if (num <= 0) return false;
    while (num % x == 0) num /= x;
    return num == 1;
}


