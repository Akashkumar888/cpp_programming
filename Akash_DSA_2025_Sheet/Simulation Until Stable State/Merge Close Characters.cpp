
class Solution {
public:
    string solve(string &s, int k){
        string akash = s;   
        while(true){
            bool merged = false;
            int n = akash.size();
            unordered_map<char,int> mp;
            
            for(int j = 0; j < n; j++){
                if(mp.find(akash[j]) != mp.end()){
                    int i = mp[akash[j]];   
                    if(j - i <= k){
                        akash.erase(j, 1);
                        merged = true;
                        break; 
                    }
                }   
                mp[akash[j]] = j;
            }   
            if(!merged) break;
        }
        return akash;
    }
    string mergeCharacters(string s, int k) {
        if(s.empty()) return "";
        return solve(s, k);
    }
};







// ✅ 1️⃣ When Do We Use while(true) + break?
// We use this pattern when:
// We don't know how many times an operation will repeat, but we know when it should stop.
// In your problem:
// We don’t know how many merges will happen.
// But we know we stop when no merge occurs in one full scan.
// So pattern becomes:

// while(true){
//     bool changed = false;
//     // try to perform operation

//     if(!changed) break;
// }

// This is called:
// 🔁 Simulation Until Stable State
// 🧠 How To Identify These Problems?
// Look for these keywords in question:
// “Repeat until no more changes”
// “Keep removing”
// “Continue merging”
// “Perform operations one at a time”
// “After each operation, update the string/array”
// “Until no more possible moves”
// Whenever you see this → Think:
// This is a simulation problem.

// 🎯 General Pattern
// while(true){
//     bool changed = false;
//     for(...) {
//         if(condition){
//             // perform operation
//             changed = true;
//             break;
//         }
//     }
//     if(!changed) break;
// }

// 📚 Problems That Use Same Pattern
// Here are common problems solved like this:

// 1️⃣ Remove Adjacent Duplicates
// LeetCode: Remove All Adjacent Duplicates
// Example:
// abbaca → remove bb → aaca → remove aa → ca
// Keep removing until no adjacent duplicates.

// 2️⃣ Candy Crush Simulation
// LeetCode: Candy Crush
// Remove groups → drop elements → repeat
// Until board becomes stable.

// 3️⃣ String Reduction Problems
// Example:
// aaabbb → remove aaa → bbb → remove bbb → empty
// 4️⃣ Game Simulation Problems
// Example:
// Remove stones
// Collapse blocks
// Merge intervals repeatedly

// 5️⃣ Graph Shrinking / Pruning Problems
// Example:
// Remove nodes with degree 1 repeatedly
// Topological elimination
// 6️⃣ Delete Leaves in Binary Tree Repeatedly
// Remove all leaves → repeat
// Until tree empty.

// ⚠️ Important Interview Concept
// This pattern is called:
// "Process Until No More Changes"
// or
// "Repeat Until Stable"
// 🚨 When NOT To Use while(true)?
// Do NOT use it when:
// Exact number of iterations known
// Pure sliding window
// DP with fixed states
// Simple one-pass problem

// 💡 Better Alternative to while(true)
// Instead of:

// while(true)
// You can write:
// bool merged = true;
// while(merged){
//     merged = false;
//     ...
// }
// Cleaner and safer.
// 🎤 How To Say in Interview
// If interviewer asks:
// Why did you use while(true)?
// You say:
// Since the number of merges is unknown and depends on dynamic updates of the string, I simulate the process and repeat until no changes occur in one full pass. That guarantees we reach a stable state.

// 🔥 Golden Rule to Identify These Problems
// If:
// Structure changes
// Indices shift
// Operation affects future operations
// Must follow specific order of operations
// Then:
// 👉 Think Simulation + Repeat Until Stable

// 1️⃣ Simulation vs Greedy
// 🔄 Simulation
// You directly imitate the process exactly as described.
// Used when:
// Order matters
// Structure keeps changing
// “After each operation update the string/array”
// Repeat until stable
// Example:
// Your mergeCharacters problem
// Candy Crush
// Repeated deletions
// Pattern:

// while(changed){
//    scan
//    perform operation
// }
// 🎯 Greedy
// Greedy makes the best decision at current step and moves forward.
// Used when:
// Local optimal → global optimal
// No need to revisit earlier states
// Example:
// Activity selection
// Minimum intervals removal

// Jump Game
// 🔥 Key Difference
// Simulation	Greedy
// Repeat until no change	One pass
// Structure keeps updating	Structure mostly stable
// May restart scanning	Move forward only

// 2️⃣ When to Use Stack Instead of while(true)?
// If operations depend only on recent elements, use stack.
// Example 1: Remove Adjacent Duplicates
// Input:
// abbaca
// Better using stack:

// for(char c : s){
//     if(!st.empty() && st.top() == c)
//         st.pop();
//     else
//         st.push(c);
// }

// Why stack works?
// Because we only compare with previous character.
// ❌ But In Your Merge Problem?
// Stack cannot work because:
// Condition depends on distance j - i <= k
// Not just adjacent
// After removal, earlier characters may again become close
// So we need simulation.

// 3️⃣ Time Complexity Thinking
// Your solution:
// Worst case:
// Each iteration removes 1 char
// n iterations
// Each iteration scans n²
// Worst: O(n³)
// But constraint:
// n <= 100
// 100³ = 1,000,000 → Safe.
// Interview Tip:
// If n ≤ 100 → brute simulation usually acceptable.
// If n ≤ 10⁵ → you must optimize.

// 4️⃣ Pattern Recognition Trick (Very Important)
// Whenever you read problem, ask:
// Step 1:
// Does structure change after operation?
// If YES → think simulation.
// Step 2:
// Does problem say:
// repeat
// until no more
// after each operation
// update structure
// If YES → simulation pattern.
// Step 3:
// Can operation be done using only recent info?
// If YES → maybe stack.

// If NO → full scan simulation.
// 🎯 Advanced Interview Insight
// There are 4 big pattern families:
// Sliding Window
// Stack/Monotonic Stack
// Greedy
// Simulation Until Stable
// Your problem belongs to type 4.

// 🚀 Next Level Thinking
// Some problems that look simulation can be optimized using:
// Doubly linked list
// Ordered set
// Queue of positions
// Graph modeling
// Senior-level trick.
// 🎤 How to Sound Smart in Interview
// You say:
// Since the string keeps updating after every merge and new possible merges can form due to index shifts, I simulate the process until no further changes occur. Because n is small, this approach is acceptable.
// That sounds strong 💪




// 🔁 🔥 SIMULATION UNTIL STABLE – PRACTICE PROBLEMS
// 🟢 1️⃣ Remove / Delete Until No Change
// These are closest to your problem.
// 1. Remove All Adjacent Duplicates in String
// Platform: LeetCode
// Pattern: Remove → update → repeat
// 2. Remove All Adjacent Duplicates in String II
// (When duplicates count = k)
// 3. Make The String Great
// (Remove adjacent opposite case letters)
// 4. 1047. Remove All Adjacent Duplicates
// 🟢 2️⃣ Candy Crush / Collapse Type Problems
// 5. Candy Crush
// Very important simulation problem.
// 6. 1209. Remove All Adjacent Duplicates in String II
// (Group removal + repeat)
// 7. Asteroid Collision
// (Simulate collisions until stable)
// 🟢 3️⃣ Repeated Pruning / Graph Shrinking
// 8. 310. Minimum Height Trees
// (Remove leaf nodes repeatedly)
// 9. 802. Find Eventual Safe States
// (Remove unsafe nodes repeatedly)
// 🟢 4️⃣ String Merge / Reduction Type
// 10. 1544. Make The String Great
// (Remove opposite cases repeatedly)
// 11. 2696. Minimum String Length After Removing Substrings
// 12. 1750. Minimum Length of String After Deleting Similar Ends
// 🟢 5️⃣ Matrix / Grid Simulation
// 13. 723. Candy Crush
// (Heavy simulation)
// 14. 130. Surrounded Regions
// (Mark and remove repeatedly)
// 15. Game of Life
// (Simulation step by step)
// 🟢 6️⃣ Stack + Simulation Hybrid
// 16. 735. Asteroid Collision
// 17. 402. Remove K Digits
// 18. 456. 132 Pattern
// 🎯 Advanced Level Simulation
// If you want stronger control:
// 19. 2038. Remove Colored Pieces if Both Neighbors are Same Color
// 20. 2211. Count Collisions on a Road
// 21. 838. Push Dominoes
// Dominoes is very famous simulation problem.
// 🔥 How To Practice Smartly
// Step 1:
// Solve simple string remove problems.
// Step 2:
// Move to stack + simulation hybrid.
// Step 3:
// Solve Candy Crush type grid simulation.
// Step 4:
// Solve graph pruning problems.
// 🧠 Pattern Recognition Drill
// When solving practice, always ask:
// Does structure change?
// Do I repeat until no more changes?
// Does order of operations matter?
// Can earlier removals create new valid removals?
// If YES → simulation until stable.
// 🚀 10-Problem Mini Practice Set (Perfect For You)
// Solve in this order:
// Remove Adjacent Duplicates
// Remove Adjacent Duplicates II
// Make The String Great
// Minimum String Length After Removing Substrings
// Asteroid Collision
// Push Dominoes
// Remove K Digits
// Candy Crush
// Minimum Height Trees
// Surrounded Regions

// 🎤 Interview Confidence Line
// You can say:
// This problem belongs to the "Simulation Until Stable State" pattern, where operations dynamically change the structure and may create new valid operations, so we repeat the process until no further changes occur.
// That sounds like 2+ years experience answer 💪