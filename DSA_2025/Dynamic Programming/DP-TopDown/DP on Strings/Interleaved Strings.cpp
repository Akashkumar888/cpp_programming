
class Solution {
  public:
//   An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, such that:
// s = s1 + s2 + ... + sn
// t = t1 + t2 + ... + tm
// |n - m| <= 1
// The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
// Note: a + b is the concatenation of strings a and b.

// “If I start recursion from the end (i = m-1, j = n-1), can I still use k = i + j instead of passing k explicitly?”
// Every character in s3 must come from s1 or s2.
// The relative order of characters in s1 and s2 must be preserved.
// The Relationship between i, j, and k
// If we take:
// i = current index in s1
// j = current index in s2
// k = current index in s3
// then at every point:
// k = i + j   (when counting from the beginning)
// Because:
// We have used i characters from s1
// And j characters from s2
// So total characters used in s3 = i + j
// Hence s3[i + j - 1] is the current character.
// 🧠 BUT — What if We Start from the END?
// If you start recursion from the end of strings:
// solve(i = m-1, j = n-1, k = o-1)
// i' = m-1 - i    how many characters have been used from s1
// j' = n-1 - j    how many characters have been used from s2
// k' = o-1 - k    how many characters have been used from s3
// We know the same relationship must hold:
// k' = i' + j'
// (o-1 - k) = (m-1 - i) + (n-1 - j)
// => o - 1 - k = m + n - 2 - (i + j)
// => k = o - 1 - (m + n - 2 - (i + j))
// => k = (i + j) - (m + n - o)
// Now, since m + n = o (that’s the precondition of interleaving strings),
// the last term (m + n - o) becomes 0.
// ✅ So even when starting from the end:
// k = i + j
// still holds perfectly.
// ⚙️ So, What Does That Mean?
// You don’t need to pass k explicitly in recursion at all —
// you can compute it as k = i + j if your indices are consistent.
// The only rule:
// you must define your dp states carefully (using either 0-based or shifted indexing).
// ✅ Recursive Implementation (from the END, using k = i + j)

int m,n,o;
  bool solve(int i, int j, string &s1, string &s2, string &s3, vector<vector<int>> &dp) {
        // ✅ Base case
        if (i == m && j == n) return true;

        // index in s3 = i + j (total characters used so far)
        int k = i + j;

        if (dp[i][j] != -1) return dp[i][j];

        bool take1 = false, take2 = false;

        // Take from s1 if match
        if (i < m && s1[i] == s3[k])
            take1 = solve(i + 1, j, s1, s2, s3, dp);

        // Take from s2 if match
        if (j < n && s2[j] == s3[k])
            take2 = solve(i, j + 1, s1, s2, s3, dp);

        return dp[i][j] = take1 || take2;
    }
    bool isInterleave(string &s1, string &s2, string &s3) {
        m = s1.size();
        n = s2.size();
        o = s3.size();

        if (m + n != o)
            return false;

        vector<vector<int>> dp(m+1 , vector<int>(n+1 , -1));
        return solve(0, 0, s1, s2, s3, dp);
    }
};


class Solution {
  public:
// “If I start recursion from the end (i = m-1, j = n-1), can I still use k = i + j instead of passing k explicitly?”
// Every character in s3 must come from s1 or s2.
// The relative order of characters in s1 and s2 must be preserved.
// The Relationship between i, j, and k
// If we take:
// i = current index in s1
// j = current index in s2
// k = current index in s3
// then at every point:
// k = i + j   (when counting from the beginning)
// Because:
// We have used i characters from s1
// And j characters from s2
// So total characters used in s3 = i + j
// Hence s3[i + j - 1] is the current character.
// 🧠 BUT — What if We Start from the END?
// If you start recursion from the end of strings:
// solve(i = m-1, j = n-1, k = o-1)
// i' = m-1 - i    how many characters have been used from s1
// j' = n-1 - j    how many characters have been used from s2
// k' = o-1 - k    how many characters have been used from s3
// We know the same relationship must hold:
// k' = i' + j'
// (o-1 - k) = (m-1 - i) + (n-1 - j)
// => o - 1 - k = m + n - 2 - (i + j)
// => k = o - 1 - (m + n - 2 - (i + j))
// => k = (i + j) - (m + n - o)
// Now, since m + n = o (that’s the precondition of interleaving strings),
// the last term (m + n - o) becomes 0.
// ✅ So even when starting from the end:
// k = i + j
// still holds perfectly.
// ⚙️ So, What Does That Mean?
// You don’t need to pass k explicitly in recursion at all —
// you can compute it as k = i + j if your indices are consistent.
// The only rule:
// you must define your dp states carefully (using either 0-based or shifted indexing).
// ✅ Recursive Implementation (from the END, using k = i + j)

    bool isInterleave(string &s1, string &s2, string &s3) {
        int m = s1.size(), n = s2.size(), o = s3.size();
        if (m + n != o) return false;

        vector<vector<bool>> dp(m+1 , vector<bool>(n+1 , false));
        dp[m][n]=true;
        for(int i=m;i>=0;i--){
            for(int j=n;j>=0;j--){
                // index in s3 = i + j (total characters used so far)
            int k = i + j;
    
            // Take from s1 if match
            if (i < m && s1[i] == s3[k])
            dp[i][j]=dp[i][j] || dp[i+1][j];
    
            // Take from s2 if match
            if (j < n && s2[j] == s3[k])
            dp[i][j]=dp[i][j] || dp[i][j+1];
            }
        }
       return dp[0][0]; 
    }
};


class Solution {
  public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        // code here
        int m = s1.size(), n = s2.size(), o = s3.size();
        if (m + n != o) return false;

        vector<bool> dp(n + 1, false);

        // Base case: when both s1 and s2 are empty
        dp[n] = true;

        for (int i = m; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                int k = i + j; // index in s3

                if (i == m && j == n)
                    dp[j] = true;
                else {
                    bool take1 = false, take2 = false;

                    if (i < m && s1[i] == s3[k])
                        take1 = dp[j]; // from previous iteration of i+1

                    if (j < n && s2[j] == s3[k])
                        take2 = dp[j + 1];

                    dp[j] = take1 || take2;
                }
            }
        }
        return dp[0];
    }
};


class Solution {
public:
int m,n,o;
  bool solve(int i, int j, string &s1, string &s2, string &s3, vector<vector<int>> &dp) {
        // Base case
        if (i < 0 && j < 0) return true;

        int k = i + j + 1; // because s3 is 0-indexed and we count used chars
        if (dp[i + 1][j + 1] != -1) return dp[i + 1][j + 1];

        bool take1 = false, take2 = false;

        if (i >= 0 && s1[i] == s3[k])
            take1 = solve(i - 1, j, s1, s2, s3, dp);

        if (j >= 0 && s2[j] == s3[k])
            take2 = solve(i, j - 1, s1, s2, s3, dp);

        return dp[i + 1][j + 1] = take1 || take2;
    }

    bool isInterleave(string &s1, string &s2, string &s3) {
        m = s1.size();
        n = s2.size();
        o = s3.size();

        if (m + n != o)
            return false;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(m - 1, n - 1, s1, s2, s3, dp);

    }
};


class Solution {
  public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        int m = s1.size(), n = s2.size(), o = s3.size();
        if (m + n != o) return false;

        vector<bool> dp(n + 1, false);

        // Base case: when both s1 and s2 are empty
        dp[n] = true;

        for (int i = m; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                int k = i + j; // index in s3

                if (i == m && j == n)
                    dp[j] = true;
                else {
                    bool take1 = false, take2 = false;

                    if (i < m && s1[i] == s3[k])
                        take1 = dp[j]; // from previous iteration of i+1

                    if (j < n && s2[j] == s3[k])
                        take2 = dp[j + 1];

                    dp[j] = take1 || take2;
                }
            }
        }
        return dp[0];
    }
};


class Solution {
  public:
// “If I start recursion from the end (i = m-1, j = n-1), can I still use k = i + j instead of passing k explicitly?”
// Every character in s3 must come from s1 or s2.
// The relative order of characters in s1 and s2 must be preserved.
// The Relationship between i, j, and k
// If we take:
// i = current index in s1
// j = current index in s2
// k = current index in s3
// then at every point:
// k = i + j   (when counting from the beginning)
// Because:
// We have used i characters from s1
// And j characters from s2
// So total characters used in s3 = i + j
// Hence s3[i + j - 1] is the current character.
// 🧠 BUT — What if We Start from the END?
// If you start recursion from the end of strings:
// solve(i = m-1, j = n-1, k = o-1)
// i' = m-1 - i    how many characters have been used from s1
// j' = n-1 - j    how many characters have been used from s2
// k' = o-1 - k    how many characters have been used from s3
// We know the same relationship must hold:
// k' = i' + j'
// (o-1 - k) = (m-1 - i) + (n-1 - j)
// => o - 1 - k = m + n - 2 - (i + j)
// => k = o - 1 - (m + n - 2 - (i + j))
// => k = (i + j) - (m + n - o)
// Now, since m + n = o (that’s the precondition of interleaving strings),
// the last term (m + n - o) becomes 0.
// ✅ So even when starting from the end:
// k = i + j
// still holds perfectly.
// ⚙️ So, What Does That Mean?
// You don’t need to pass k explicitly in recursion at all —
// you can compute it as k = i + j if your indices are consistent.
// The only rule:
// you must define your dp states carefully (using either 0-based or shifted indexing).
// ✅ Recursive Implementation (from the END, using k = i + j)

int m,n,o;
  bool solve(int i, int j, string &s1, string &s2, string &s3, vector<vector<int>> &dp) {
        // Base cases FIRST (before dp access)
        if (i < 0 && j < 0)
            return true;

        int k = i + j + 1;  // current index in s3

        // Handle out-of-bound cases before checking dp
        if (i < 0)
            return s2[j] == s3[k] && solve(i, j - 1, s1, s2, s3, dp);
        if (j < 0)
            return s1[i] == s3[k] && solve(i - 1, j, s1, s2, s3, dp);

        // Now it's safe to check dp[i][j]
        if (dp[i][j] != -1)
            return dp[i][j];

        bool take1 = false, take2 = false;

        // Try taking from s1
        if (s1[i] == s3[k])
            take1 = solve(i - 1, j, s1, s2, s3, dp);

        // Try taking from s2
        if (s2[j] == s3[k])
            take2 = solve(i, j - 1, s1, s2, s3, dp);

        return dp[i][j] = take1 || take2;
    }
    bool isInterleave(string &s1, string &s2, string &s3) {
        m = s1.size();
        n = s2.size();
        o = s3.size();

        if (m + n != o)
            return false;

        vector<vector<int>> dp(m , vector<int>(n , -1));
        return solve(m - 1, n - 1, s1, s2, s3, dp);

    }
};
