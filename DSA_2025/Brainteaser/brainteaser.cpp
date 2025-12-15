
// 1) What is a brainteaser (in interviews)?

// A brainteaser is a short, often non-standard problem intended to test problem-solving, analytical thinking, and pattern recognition rather than rote knowledge. In interviews they often appear as puzzles that require one or more of: math insights, clever data structures, search (BFS/DFS), dynamic programming, greedy reasoning, or bit tricks.
// Common goals interviewers evaluate:
// decomposition of the problem
// selecting an efficient approach (time/space tradeoffs)
// communicating reasoning clearly
// producing correct, maintainable code

// 2) Categories & common solving strategies
// Math / Logic puzzles — look for invariant, parity, modular arithmetic, powers of two
// State-space search — model states and transitions and run BFS/DFS (Water-Jug, puzzle states)
// Greedy / constructive — find a local rule that leads to global optimum (some egg drop variants)
// Dynamic Programming — optimal substructure and overlapping subproblems (egg dropping, knapsack-like)
// Simulation with data structures — queues, stacks, circular lists (Josephus)
// Bit manipulation — rotate, mask, highest power of two (some Josephus tricks)
// Strategy checklist when you see a brainteaser
// Restate the problem and constraints.
// Try small examples by hand.
// Look for invariants/patterns and minimal states.
// Choose modeling (graph of states? DP table? math formula?).
// Consider complexity and optimize (memoize, reduce state).
// Write correct code, then edge cases/tests.
// 3) Three classic brainteasers (practice problems + C++ code)
// I picked Josephus, Water Jug, and Egg Drop (Super Egg Drop) — these cover math/bit tricks, BFS/state search, and DP respectively. Links to LeetCode/GFG are included so you can try them online. 
// LeetCode
// LeetCode
// GeeksforGeeks

// A — Josephus Problem (circular elimination)
// Idea: There is a well-known O(n) iterative formula: let res = 0. For i = 1..n: res = (res + k) % i. Final answer = res + 1 (1-indexed). This is derived from solving the recurrence for the survivor.
// Practice links: LeetCode “Find the Winner of the Circular Game” / GFG Josephus

// C++ (iterative formula — O(n), O(1) space)
// #include <bits/stdc++.h>
// using namespace std;

// // Returns 1-based position of winner (Josephus)
// int josephus(int n, int k) {
//     int res = 0; // 0-based
//     for (int i = 1; i <= n; ++i) {
//         res = (res + k) % i;
//     }
//     return res + 1; // convert to 1-based
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n = 5, k = 2; // example
//     cout << "Winner: " << josephus(n, k) << '\n'; // should print 3 for (5,2)
//     return 0;
// }

// B — Water Jug (measure target using two jugs)

// Idea: Model states as (x, y) = current amounts; transitions are fill, empty, pour. Run BFS over state graph to find if we can reach the target amount. Use visited set to avoid repeats. (Key math insight: target must be multiple of gcd(x, y) and ≤ max(x, y) — quick reject.)

// Practice links: LeetCode 365 and GFG Water Jug. 


// C++ (BFS + gcd quick check)
// #include <bits/stdc++.h>
// using namespace std;

// bool canMeasureWater(int x, int y, int target) {
//     if (target > max(x, y)) return false;
//     int g = std::gcd(x, y);
//     if (target % g != 0) return false;

//     // BFS over states (a, b)
//     queue<pair<int,int>> q;
//     unordered_set<long long> seen; // encode pair into long long
//     auto encode = [](int a, int b){ return ( (long long)a << 32 ) | (unsigned long long)b; };

//     q.push({0, 0});
//     seen.insert(encode(0,0));

//     while (!q.empty()) {
//         auto [a,b] = q.front(); q.pop();
//         if (a == target || b == target || a + b == target) return true;

//         vector<pair<int,int>> next;
//         // fill x
//         next.push_back({x, b});
//         // fill y
//         next.push_back({a, y});
//         // empty x
//         next.push_back({0, b});
//         // empty y
//         next.push_back({a, 0});
//         // pour x -> y
//         int pour = min(a, y - b);
//         next.push_back({a - pour, b + pour});
//         // pour y -> x
//         pour = min(b, x - a);
//         next.push_back({a + pour, b - pour});

//         for (auto &ns : next) {
//             long long code = encode(ns.first, ns.second);
//             if (!seen.count(code)) {
//                 seen.insert(code);
//                 q.push(ns);
//             }
//         }
//     }
//     return false;
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout << boolalpha;
//     cout << canMeasureWater(3,5,4) << '\n'; // true
//     cout << canMeasureWater(2,6,5) << '\n'; // false
//     return 0;
// }

// C — Egg Dropping — Super Egg Drop (LeetCode 887)

// Idea (efficient approach): Instead of DP over floors directly, count how many floors we can test with m moves and k eggs. Let dp[e] be max floors checkable with e eggs and current moves m. Recurrence:

// dp[e] = dp[e] + dp[e-1] + 1


// (when we increase moves by 1, iterate eggs downward). Increase moves until dp[k] >= n. This approach is much faster than naive O(k*n^2) DP. Practice link: LeetCode 887 

// C++ (moves-based DP; O(k * log n) in practice)
// #include <bits/stdc++.h>
// using namespace std;

// // returns minimum moves to determine critical floor with k eggs and n floors
// int superEggDrop(int k, int n) {
//     if (n == 0) return 0;
//     vector<long long> dp(k + 1, 0);
//     int moves = 0;
//     while (dp[k] < n) {
//         moves++;
//         for (int e = k; e >= 1; --e) {
//             dp[e] = dp[e] + dp[e - 1] + 1;
//         }
//     }
//     return moves;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout << superEggDrop(2, 10) << '\n'; // example: 4
//     cout << superEggDrop(3, 14) << '\n';
//     return 0;
// }
// This version is used in many interview/competitive solutions and scales well for typical constraints.

// Practice plan & tips

// Start with small puzzles (2-3 examples) and force yourself to explain steps aloud.
// Implement BFS/DFS, a DP template, and common math patterns (gcd, powers of two, modular).
// Time yourself on 10–15 practice problems (GFG / LeetCode) and review optimized solutions.
// When stuck: write brute force logic, show interviewer the correctness of brute force, then optimize. Interviewers appreciate a correct brute force plus path to optimize.

// 5) Links for practice (click to open)
// LeetCode — Find the Winner of the Circular Game (Josephus). 
// LeetCode
// GeeksforGeeks — Josephus: explanation & bit trick. 
// GeeksforGeeks
// LeetCode — Water and Jug Problem (365). 
// LeetCode
// GeeksforGeeks — Water Jug (BFS). 
// GeeksforGeeks
// LeetCode — Super Egg Drop (887). 
// LeetCode
// GeeksforGeeks — Egg Dropping / 2 eggs & k floors articles

