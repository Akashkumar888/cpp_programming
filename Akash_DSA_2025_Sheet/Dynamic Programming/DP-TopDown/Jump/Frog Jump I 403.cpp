class Solution {
public:
// determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.
// If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.
bool solve(int curr_idx,int prev_jump,int n,vector<int>&stones,unordered_map<int,int>&mp,vector<vector<int>>&dp){
  if(curr_idx==n-1)return true;
  if(dp[curr_idx][prev_jump]!=-1)return dp[curr_idx][prev_jump];
  bool result=false;
  for (int nextJump = prev_jump - 1; nextJump <= prev_jump + 1; nextJump++){
    if(nextJump>0){
    int nextStone=stones[curr_idx]+nextJump;
    if(mp.find(nextStone)!=mp.end()){
        int nextIdx = mp[nextStone];
        result = result || solve(nextIdx, nextJump, n, stones, mp, dp);
    }
  }
}
 return dp[curr_idx][prev_jump]= result;
}
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        if (stones[1] != 1) return false; // first jump must be 1
        unordered_map<int,int>mp;
        for (int i = 0; i < n; i++) mp[stones[i]] = i;
        return solve(1,1,n,stones,mp,dp);
    }
};

// Direction matters!
// Top-down → moves forward via recursion.
// Bottom-up → must fill forward instead of backward dependency.

// Rule still holds:

// "Jo pahle se loop hai use rehne do"
// But the update direction must match how states depend on each other.

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (stones[1] != 1) return false; // first jump must be 1

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) mp[stones[i]] = i;

        vector<vector<bool>> dp(n, vector<bool>(n + 1, false)); // is array me bottom up me jo chahiye uske opposite bhr do 
        // min-chahiye       -> INT_MAX bhr do
        // max-chahiye       -> INT_MIN bhr do
        // count-chahiye     -> 0 bhr do
        // true-chahiye      -> false bhr do
        // false-chahiye     -> true bhr do
        // sum-chahiye       -> 0 bhr do
        // product-chahiye   -> 1 bhr do
        // length-chahiye    -> 0 bhr do
        // ways-chahiye      -> 0 bhr do
        // possible-chahiye  -> false bhr do
        // not-possible-chahiye -> true bhr do
        // string answer chahiye -> "" bhr do (empty string)
        // pair (min,max) chahiye -> {INT_MAX, INT_MIN} bhr do
        // dp state me invalid ka matlab ho -> -1 bhr do
        // prefix/suffix dp ke liye base case -> dp[0] = 0 ya dp[0] = 1 depending on problem

        dp[0][0] = true;  // starting at stone 0 with 0 jump

        for (int i = 0; i < n; i++) {
            for (int k = 0; k <= n; k++) {
                if (dp[i][k]) {
                    for (int jump = k - 1; jump <= k + 1; jump++) {
                        if (jump > 0) {
                            int nextStone = stones[i] + jump;
                            if (mp.find(nextStone) != mp.end()) {
                                int nextIdx = mp[nextStone];
                                dp[nextIdx][jump] = true;
                            }
                        }
                    }
                }
            }
        }

        // if any jump leads to last stone
        for (int k = 0; k <= n; k++) {
            if (dp[n - 1][k]) return true;
        }
        return false;
    }
};
