// 🚀 Where Catalan Numbers Are Used in DSA
// Catalan number formula:
// Cn = Σ (Ci * Cn-i-1)
// 👉 It usually appears when:
// You are dividing a structure into left + right parts
// And both parts are independent

// 🧩 Most Important Catalan-Based Problems
// 1. ✅ Unique BST Count
// 👉 Count number of BSTs from n nodes
// 👉 Same as your problem
// Formula:
// Total BST = Catalan(n)

// 2. ✅ Valid Parentheses / Balanced Brackets
// 👉 Number of valid parentheses combinations
// Example:
// n = 3 → ()()(), (()), etc.
// Answer = Catalan(n)

// 3. ✅ Number of Binary Trees with n nodes
// 👉 Count structurally unique binary trees

// 4. ✅ Full Binary Trees Count
// 👉 Nodes = odd → Catalan based

// 5. ✅ Ways to Triangulate a Polygon
// 👉 Divide polygon into triangles

// 6. ✅ Non-Crossing Chords in Circle
// 👉 Classic interview problem

// 7. ✅ Dyck Paths (Grid Paths without crossing diagonal)
// 8. ✅ Stack Permutations
// 👉 Number of valid stack sequences

// 9. ✅ Expression Tree Formation
// 👉 Different ways to parenthesize expressions
// 🧠 Pattern Recognition Trick (VERY IMPORTANT)

// 👉 If problem says:
// "Divide into left and right"
// "Count structures"
// "Valid combinations"
// "Recursive splitting"
// ➡️ Think: Catalan Number

// ⚡ Optimized Catalan Formula (Interview Gold)
// Instead of O(N²), use:
// Cn = (2n)! / ((n+1)! * n!)
// Or iterative:

// long long catalan(int n) {
//     long long res = 1;
//     for(int i = 0; i < n; i++) {
//         res = res * (2*n - i) / (i + 1);
//     }
//     return res / (n + 1);
// }
// 🔥 When to Use Your DP Version?
// Your code 👇
// catalan[i] += catalan[j] * catalan[i-j-1];
// 👉 Use when:
// n ≤ 1000 (safe DP)
// Need all values from 0 → n
// Avoid factorial overflow
// ⚠️ Common Interview Mistake
// People memorize formula but fail to identify problem
// 👉 Focus on pattern:
// "Left subtree × Right subtree"
// That is the biggest hint of Catalan
// 💡 Pro Tip for You
// Whenever you see:
// BST counting
// Parentheses
// Tree structure count
// 👉 Immediately think:
// 🔥 "Is this Catalan?"

class Solution {
  public:
// We are given a sorted array of distinct elements, say:
// arr = [2, 1, 3]
// When a particular element arr[i] is chosen as the root of a Binary Search Tree (BST):
// All smaller elements go to the left subtree
// All greater elements go to the right subtree
// We must find how many unique BSTs can be formed with that root.
// ⚙️ Core Idea (Catalan Concept)
// For any set of n distinct numbers,
// the total number of unique BSTs = Catalan number Cₙ = (2n)! / ((n+1)! n!)
// But here, instead of total BSTs, we are finding for each element how many BSTs are possible when that element is the root.
// 🧮 Approach
// Sort the array (if not already sorted) — BST structure depends on relative order.
// For each element arr[i]:
// Elements to the left of it → can form L nodes in the left subtree.
// Elements to the right of it → can form R nodes in the right subtree.
// The number of unique BSTs when arr[i] is root = count(i)=Catalan(L)×Catalan(R)
// because:
// Left subtree can be formed in Catalan(L) ways.
// Right subtree can be formed in Catalan(R) ways.
// Combine both sides (independent choices multiply).

    // Function to compute Catalan numbers using DP
    vector<long long> computeCatalan(int n) {
        vector<long long> catalan(n + 1, 0);
        catalan[0] =1 ;
        catalan[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }
        return catalan;
    }
    vector<int> countBSTs(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> result(n, 0);

        // store original order
        vector<int> original = arr;

        // Step 1: Sort the array (for BST logic)
        sort(arr.begin(), arr.end());

        // Step 2: Precompute Catalan numbers
        vector<long long> catalan = computeCatalan(n);

        // Step 3: Map element → count
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int L = i; // curr 
            int R = n - 1 -i; // last 
            mp[arr[i]] = catalan[L] * catalan[R];
        }

        // Step 4: Rebuild result in original order
        for (int i = 0; i < n; i++) {
            result[i] = mp[original[i]];
        }

        return result;
    }
};




class Solution {
  public:
// We are given a sorted array of distinct elements, say:
// arr = [2, 1, 3]
// When a particular element arr[i] is chosen as the root of a Binary Search Tree (BST):
// All smaller elements go to the left subtree
// All greater elements go to the right subtree
// We must find how many unique BSTs can be formed with that root.
// ⚙️ Core Idea (Catalan Concept)
// For any set of n distinct numbers,
// the total number of unique BSTs = Catalan number Cₙ = (2n)! / ((n+1)! n!)
// But here, instead of total BSTs, we are finding for each element how many BSTs are possible when that element is the root.
// 🧮 Approach
// Sort the array (if not already sorted) — BST structure depends on relative order.
// For each element arr[i]:
// Elements to the left of it → can form L nodes in the left subtree.
// Elements to the right of it → can form R nodes in the right subtree.
// The number of unique BSTs when arr[i] is root =
// count(i)=Catalan(L)×Catalan(R)
// because:
// Left subtree can be formed in Catalan(L) ways.
// Right subtree can be formed in Catalan(R) ways.
// Combine both sides (independent choices multiply).
// Function to compute Catalan numbers using DP
    vector<long long>computeCatalan(int n){
        vector<long long>catalan(n+1,0);
        catalan[0]=1;
        catalan[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                catalan[i] = catalan[i] + catalan[j]*catalan[i-j-1];
            }
        }
        return catalan;
    }
    vector<int> countBSTs(vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int>result(n,0);
        // store original order
        vector<int>original=arr;
        // Step 1: Sort the array (for BST logic)
        sort(arr.begin(),arr.end());
        // Step 2: Precompute Catalan numbers
        vector<long long>catalan=computeCatalan(n);
        // Step 3: Map element → count
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int L=i; // curr 
            int R=n-1-i; // last 
            mp[arr[i]]=catalan[L]*catalan[R];
        }
        // Step 4: Rebuild result in original order
        for(int i=0;i<n;i++){
            result[i]=mp[original[i]];
        }
        return result;
    }
};



class Solution {
  public:
    const int MOD = 1e9+7;
    vector<long long> computeCatalan(int n){
        vector<long long> catalan(n+1, 0);
        // ✅ initialization (IMPORTANT)
        catalan[0] = 1;
        if(n >= 1) catalan[1] = 1;

        for(int i = 2; i <= n; i++){
            for(int j = 0; j < i; j++){
                catalan[i] = (catalan[i] + 
                             (catalan[j] * catalan[i-j-1]) % MOD) % MOD;
            }
        }
        return catalan;
    }
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, 0);
        vector<int> original = arr;
        sort(arr.begin(), arr.end());
        vector<long long> catalan = computeCatalan(n);
        unordered_map<int,long long> mp;
        for(int i = 0; i < n; i++){
            int L = i;
            int R = n - 1 - i;
            // ✅ MOD safe multiplication
            mp[arr[i]] = (catalan[L] * catalan[R]) % MOD;
        }
        for(int i = 0; i < n; i++){
            result[i] = mp[original[i]];
        }
        return result;
    }
};


// 🚀 What I Fixed (Important)
// ✅ 1. Initialization
// catalan[0] = 1;
// catalan[1] = 1;
// ✅ 2. Overflow Fix
// (catalan[j] * catalan[i-j-1]) % MOD
// ✅ 3. Large n Support
// Works for n up to ~1000 safely
// No overflow

// CP-ready
// ⚠️ Still Limitation
// 👉 This is O(N²)
// So:
// n ≤ 1000 → ✅ OK
// n ≥ 1e5 → ❌ TLE

// 🔥 If interviewer pushes further
// Say:
// “We can optimize using nCr and modular inverse to get O(N)”
// 💡 Final Tip for You
// 👉 For GFG / Interviews → this code is PERFECT
// 👉 For CP (Codeforces/AtCoder) → need:
// nCr + mod inverse version



class Solution {
  public:
    const int MOD = 1e9+7;
    const int MAXN = 200005;

    vector<long long> fact, invFact;

    // 🔥 Fast Power (Binary Exponentiation)
    long long power(long long a, long long b){
        long long res = 1;
        while(b){
            if(b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    // 🔥 Precompute factorials and inverse factorials
    void precompute(int n){
        fact.resize(2*n + 1);
        invFact.resize(2*n + 1);

        fact[0] = 1;
        for(int i = 1; i <= 2*n; i++){
            fact[i] = (fact[i-1] * i) % MOD;
        }

        // Fermat inverse
        invFact[2*n] = power(fact[2*n], MOD-2);

        for(int i = 2*n-1; i >= 0; i--){
            invFact[i] = (invFact[i+1] * (i+1)) % MOD;
        }
    }

    // 🔥 nCr using factorial
    long long nCr(int n, int r){
        if(r > n || r < 0) return 0;
        return (fact[n] * invFact[r] % MOD * invFact[n-r] % MOD) % MOD;
    }

    // 🔥 Catalan using formula
    long long catalan(int n){
        long long res = nCr(2*n, n);
        res = (res * power(n+1, MOD-2)) % MOD;
        return res;
    }

    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, 0);

        vector<int> original = arr;
        sort(arr.begin(), arr.end());

        // 🔥 Precompute once
        precompute(n);

        unordered_map<int,long long> mp;

        for(int i = 0; i < n; i++){
            int L = i;
            int R = n - 1 - i;

            long long left = catalan(L);
            long long right = catalan(R);

            mp[arr[i]] = (left * right) % MOD;
        }

        for(int i = 0; i < n; i++){
            result[i] = mp[original[i]];
        }

        return result;
    }
};


// 🧠 What You Just Learned (VERY IMPORTANT)
// ✅ Catalan Formula Used
// Cn = nCr(2n, n) / (n+1)
// ✅ Why Modular Inverse?
// Division is not allowed in mod → so:

// divide by (n+1) → multiply by inverse(n+1)
// ✅ Time Complexity
// Step	Complexity
// Precompute factorial	O(N)
// Each Catalan	O(1)
// Total	🔥 O(N)
// ⚡ When to Use This Version
// 👉 Use this when:
// n ≥ 1000
// Competitive Programming
// Interview optimization round
// Constraints like 1e5 or 1e6

// ⚠️ Interview Gold Line
// If interviewer asks:

// 👉 “Can you optimize?”
// Say confidently:
// “Yes, using combinatorics: Catalan = nCr(2n,n)/(n+1) with modular inverse, reducing complexity to O(N)”
// 🔥 This line = selection signal

// 💡 Final Advice for You
// Situation	Use
// GFG POTD	DP version
// Interviews	DP + mention optimization
// CP / FAANG	THIS version 🔥

// 👉 Top FAANG problems where this optimization is required
// 👉 or mod inverse + nCr template you can reuse everywhere




// 🧠 1️⃣ ONE-LINE UNDERSTANDING (Most Important)
// 👉 Catalan = ways to split into left × right
// Total ways = Left × Right
// That’s it.
// If you remember only this → you can solve most problems.

// 🚀 2️⃣ SUPER SIMPLE PATTERN
// Whenever you see:
// 👉 Choose something as root
// 👉 Left side independent
// 👉 Right side independent
// Then:
// Answer = LeftWays * RightWays
// 🔥 That is Catalan pattern

// 🧩 3️⃣ VISUAL UNDERSTANDING (BEST)
// Example: n = 3
// Pick root:
// Root	Left nodes	Right nodes
// 1	0	2
// 2	1	1
// 3	2	0
// Now:
// Total = C0*C2 + C1*C1 + C2*C0
// 👉 This is exactly:
// Cn = Σ (Ci * Cn-i-1)

// ⚡ 4️⃣ FASTEST WAY TO THINK IN INTERVIEW
// Don’t think formula first ❌
// Think like this ✅:

// 👉 “If I pick one element as root…”
// 👉 “Left subtree ways?”
// 👉 “Right subtree ways?”
// 👉 “Multiply both”

// 🔥 5️⃣ EASIEST IMPLEMENTATION (FOR YOU)
// Use this always (clean + safe):

// vector<long long> catalan(int n){
//     vector<long long> dp(n+1,0);
//     dp[0]=1;

//     for(int i=1;i<=n;i++){
//         for(int j=0;j<i;j++){
//             dp[i] += dp[j]*dp[i-j-1];
//         }
//     }
//     return dp;
// }

// 👉 This is the most understandable version

// ⚡ 6️⃣ SHORTCUT VALUES (MEMORIZE SMALL ONES)
// n	Catalan
// 0	1
// 1	1
// 2	2
// 3	5
// 4	14
// 5	42


// 👉 Interviewers sometimes ask directly

// 🚀 7️⃣ HOW TO IDENTIFY IN 5 SECONDS
// If problem says:
// ✔ Count BST
// ✔ Valid parentheses
// ✔ Structure count
// ✔ Divide into parts
// 👉 Immediately think:
// 🔥 “This is Catalan”

// ⚡ 8️⃣ FAST VS EASY (Your Final Decision)
// Type	Use
// Easy understanding	DP (your code) ✅
// Medium optimization	DP + MOD
// High level	nCr + inverse
// 🧠 FINAL INTERVIEW LINE (VERY IMPORTANT)

// Say this confidently:
// “This is a Catalan problem because we are dividing into independent left and right substructures, so total ways = left × right”
// 🔥 This line = strong impression

// 💡 FINAL SUMMARY (REMEMBER THIS)
// 👉 Catalan = divide + multiply
// 👉 Left × Right
// 👉 Recursive split