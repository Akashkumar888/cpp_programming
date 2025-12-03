
// Algorithm:
// Pre-compute the prefix sum of ASCII values
// Create Next Index table to optimize jump lookups. It will store the next occurrence of the character ‘ch’, after its present occurrence, and it will help us to jump efficiently.
// Build the Graph of allowed jumps. The graph will tell us all the characters you can jump from a given character.
// Use Dynamic Programming or DP to compute each index score,
// Return the 0th index value.
class Solution {
public:
    // ---------- DP FUNCTION (separate) ----------
    int solve(int idx, int n, string &s,vector<vector<char>> &adj,vector<vector<int>> &nextInd,vector<int> &prefix,vector<int> &dp){
        if (idx == n - 1) return 0;
        if (dp[idx] != -1) return dp[idx];
        int best = 0;
        char curr = s[idx];
        for (char &ch : adj[curr - 'a']) {
            int target = nextInd[idx][ch - 'a'];
            if (target == -1) continue;
            int gain;
            if (ch == curr) {
                gain = prefix[target] - prefix[idx + 1];
            } 
            else {
                gain = prefix[target] - prefix[idx];
            }
            best = max(best, gain + solve(target, n, s, adj, nextInd, prefix, dp));
        }
        return dp[idx] = best;
    }
    // ---------- MAIN FUNCTION ----------
    int maxScore(string s, vector<vector<char>> &jumps) {
        int n = s.size();
        // ---------- BUILD ADJ LIST ----------
        vector<vector<char>> adj(26);
        for (auto &jp : jumps) {
            char u = jp[0];
            char v = jp[1];
            adj[u - 'a'].push_back(v);
        }
        // every character can jump to itself
        for (int c = 0; c < 26; c++){
            adj[c].push_back(char('a' + c));
        }
        // ---------- PREFIX SUM ----------
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++){
            prefix[i] = prefix[i - 1] + s[i - 1];
        }
        // ---------- NEXT OCCURRENCE TABLE ----------
        vector<vector<int>> nextInd(n, vector<int>(26, -1));
        vector<int> last(26, -1);
        for (int i = n - 1; i >= 0; i--) {
            for (int c = 0; c < 26; c++){
                nextInd[i][c] = last[c];
            }
            last[s[i] - 'a'] = i;
        }
        // ---------- DP ----------
        vector<int> dp(n, -1);
        return solve(0, n, s, adj, nextInd, prefix, dp);
    }
};