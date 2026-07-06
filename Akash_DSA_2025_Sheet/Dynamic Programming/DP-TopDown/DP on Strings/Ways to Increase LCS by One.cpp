
class Solution {
  public:
    int waysToIncreaseLCSBy1(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();
        // Prefix LCS
        vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i - 1] == s2[j - 1]){
                    pre[i][j] = 1 + pre[i - 1][j - 1];
                }
                else{
                    pre[i][j] = max(pre[i - 1][j], pre[i][j - 1]);
                }
            }
        }

        // Suffix LCS
        vector<vector<int>> suf(n + 2, vector<int>(m + 2, 0));
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                if(s1[i] == s2[j]){
                    suf[i][j] = 1 + suf[i + 1][j + 1];
                }
                else{
                    suf[i][j] = max(suf[i + 1][j], suf[i][j + 1]);
                }
            }
        }

        int lcs = pre[n][m];
        int ans = 0;

        // Try every insertion position
        for(int pos = 0; pos <= n; pos++){
            vector<int> used(26, 0);
            // Try matching every character of s2
            for(int j = 0; j < m; j++){
                char ch = s2[j];
                if(used[ch - 'a']) continue;
                if(pre[pos][j] + 1 + suf[pos][j + 1] == lcs + 1){
                    ans++;
                    used[ch - 'a'] = 1;
                }
            }
        }
        return ans;
    }
};