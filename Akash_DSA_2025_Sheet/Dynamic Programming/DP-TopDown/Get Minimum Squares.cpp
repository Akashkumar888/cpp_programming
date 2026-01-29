
class Solution {
  public:
  int solve(int i,vector<int>&arr,int tr,vector<vector<int>>&dp){
      if(tr == 0) return 0;// ✅ no more squares needed
    //   DP Initialization & Base Case Cheatsheet (Top-Down / Memoization Style)
        // ✅ When to use what in recursion + memoization
        // min-chahiye       -> return INT_MAX  (ya large number like 1e9 when not possible)
        // max-chahiye       -> return INT_MIN
        // count-chahiye     -> return 0
        // true-chahiye      -> return false  (base invalid case)
        // false-chahiye     -> return true   (base valid case if needed)
        // sum-chahiye       -> return 0
        // product-chahiye   -> return 1
        // length-chahiye    -> return 0
        // ways-chahiye      -> return 0
        // possible-chahiye  -> return false
        // not-possible-chahiye -> return true
        // string answer chahiye -> return "" (empty string)
        // pair (min,max) chahiye -> return {INT_MAX, INT_MIN}
        // dp state me invalid ka matlab ho -> return -1
        // prefix/suffix dp ke liye base case -> i==0 ya tr==0 -> return 0 ya 1 as per problem
        // invalid state (like tr<0 ya i<0) -> return 1e9 (for min) / 0 (for count) / false (for bool)
      if(tr<0 || i<0)return 1e9;
      if(dp[i][tr]!=-1)return dp[i][tr];
      //   ✅ Instead initialize to infinity (1e9) like coin change DP:
      int pick = 1e9;
      int notpick = 1e9;
      // ✅ When to use what in recursion + memoization
        // min-chahiye       -> return INT_MAX  (ya large number like 1e9 when not possible)
        // max-chahiye       -> return INT_MIN
        // count-chahiye     -> return 0
        // true-chahiye      -> return false  (base invalid case)
        // false-chahiye     -> return true   (base valid case if needed)
        // sum-chahiye       -> return 0
        // product-chahiye   -> return 1
        // length-chahiye    -> return 0
        // ways-chahiye      -> return 0
        // possible-chahiye  -> return false
        // not-possible-chahiye -> return true
        // string answer chahiye -> return "" (empty string)
        // pair (min,max) chahiye -> return {INT_MAX, INT_MIN}
        // dp state me invalid ka matlab ho -> return -1
        // prefix/suffix dp ke liye base case -> i==0 ya tr==0 -> return 0 ya 1 as per problem
        // invalid state (like tr<0 ya i<0) -> return 1e9 (for min) / 0 (for count) / false (for bool)
      int value = arr[i] * arr[i];
      // pick (unlimited supply)
      if(value<=tr)pick=1+solve(i,arr,tr-value,dp);// unlimites supply of numbers
      // not pick
      notpick=solve(i-1,arr,tr,dp);
      return dp[i][tr]= min(pick,notpick);
  }
    int minSquares(int n) {
        // Code here
        vector<int>arr;
        for(int i=1;i*i<=n;i++){
            arr.push_back(i);
        }
        vector<vector<int>> dp(arr.size(), vector<int>(n+1, -1));
        return solve(arr.size()-1,arr,n,dp);
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
    int minSquares(int n) {
        // Code here
        vector<int>arr;
        for(int i=1;i*i<=n;i++){
            arr.push_back(i);
        }
        int m = arr.size();
        const int INF = 1e9;
        vector<vector<int>> dp(m, vector<int>(n + 1, INF));
        // DP Initialization & Base Case Cheatsheet (Top-Down / Memoization Style)
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

        // base: 0 sum requires 0 squares
        for (int i = 0; i < m; i++) dp[i][0] = 0;

        // fill first row (i = 0), square = 1*1 = 1
        int val0 = arr[0] * arr[0];
        for (int sum = 1; sum <= n; sum++) {
            if (sum % val0 == 0) dp[0][sum] = sum / val0; // only using 1^2 repeatedly
            // else dp[0][sum] remains INF
        }
        //is 100% the correct and golden rule of converting recursion → bottom-up DP.
        //"jitna number of states change ho utna hi loops lagao aur jo pahle se loop hai use rahne do in bottom-up"
        // 🌟 Golden Rules for Converting Recursion → Bottom-Up DP 🌟
        // 1️⃣ No. of changing states → "Jitna number of states change ho utna hi loops lagao"
        //     👉 Here, 2 states → loop for i (index) and sum (target)
        // 2️⃣ Base initialization → "Jo chahiye uske opposite bharo"
        //     👉 We need min → fill with large number (INF)
        // 3️⃣ Transition logic → "Jo pahle se loop hai use rehne do"
        //     👉 pick/notPick same as recursion
        // 4️⃣ Base case → "Starting point aur initial state manually set karo"
        //     👉 dp[i][0] = 0
        // 5️⃣ Final check → "End tak pohchne wale sab possible states check karo"
        //     👉 return dp[m-1][n];
        // fill rest rows
        for (int i = 1; i < m; i++) {
            //✅ Instead initialize to infinity (1e9) like coin change DP:
            int value = arr[i] * arr[i];
            for (int sum = 1; sum <= n; sum++) {
                int pick = INF;
                int notpick=INF;
                // pick (unlimited supply)
                if (value <= sum) pick = 1 + dp[i][sum - value];// unlimites supply of numbers
                 // unlimited supply -> stay at i
                 // not pick
                notpick = dp[i - 1][sum];
                dp[i][sum] = min(pick, notpick);
            }
        }
        return dp[arr.size()-1][n];
    }
};


// ⚡ Key Maths Concepts (Legendre's Three-Square Theorem)
// Every natural number can be represented as the sum of four or fewer perfect squares.
// So answer ∈ {1, 2, 3, 4}.
// Rules:
// 1️⃣ If n is itself a perfect square → answer = 1
// 2️⃣ If n = a² + b² → answer = 2
// 3️⃣ If n is of form 4^k * (8m + 7) → answer = 4
// 4️⃣ Else → answer = 3

class Solution {
public:
    bool isPerfectSquare(int x){
        int num = sqrt(x);
        return num*num == x;
    }

    int minSquares(int n) {
        if (isPerfectSquare(n)) return 1; // Case 1

        // Case 2: Check if sum of two perfect squares
        for (int i = 1; i * i <= n; i++){
            if (isPerfectSquare(n - i*i)) 
                return 2;
        }

        // Case 3: Legendre's condition: n = 4^k * (8m + 7)
        int temp = n;
        while (temp % 4 == 0) temp /= 4; 
        if (temp % 8 == 7) return 4;

        // Case 4
        return 3;
    }
};