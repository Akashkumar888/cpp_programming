
// 🧠 Why Weighted Median Works?
// We want to minimize:
// f(H)=∑∣heights[i]−H∣×cost[i]
// This is:
// 👉 Weighted absolute difference minimization
// Important Theory
// If all costs were 1 → answer = normal median
// If costs are different → answer = weighted median
// Because:
// The minimum of sum of weighted absolute deviations occurs at the weighted median.
// 🎯 What is Weighted Median?
// Pair height with cost
// Sort by height
// Compute total weight
// Find first height where cumulative weight ≥ totalWeight / 2
// That height is the optimal answer.


// ❓ Why weighted median works?
// You say:
// Because the objective function is the sum of weighted absolute differences.
// Such functions are minimized at the weighted median due to convexity properties.


// 🧠 1️⃣ First Understand the Core Problem

// Most weighted median problems look like this:



// Minimize ∑∣xi−H∣ × wi
// Where:

// x_i → value (height, position, etc.)
// w_i → weight (cost, frequency, population, etc.)
// H → target value we must choose
// 🔥 2️⃣ Why Weighted Median Works (Intuition)
// Imagine a number line:
//  1    3    7    10
//  w=5  w=2  w=6   w=1

// Each point pulls the target toward itself proportional to weight.
// The optimal point is where:
// Total weight on left ≈ Total weight on right
// That balancing point is the weighted median.

// 📌 Definition (Universal Formula)
// After sorting by value:
// The weighted median is the first element where:
// Cumulative Weight ≥ Total Weight/2

// 🚀 3️⃣ Universal Algorithm (For ANY Problem)
// Step 1️⃣ Pair values with weights
// (value, weight)

// Step 2️⃣ Sort by value
// Step 3️⃣ Compute total weight
// Step 4️⃣ Find weighted median
// Keep adding weights until:
// currWeight >= (totalWeight + 1)/2
// That value = optimal target.
// Step 5️⃣ Compute final cost

// That sounds very strong.
// 🧩 How to Identify These Problems?
// Look for:
// Minimize Σ |xi - k| * wi
// Keywords:
// Make all elements equal
// Cost proportional to difference
// Absolute difference
// Minimize total moves
// 🔥 Types of Problems Using This Concept
// 1️⃣ Make All Elements Equal
// minimize Σ |arr[i] - x|
// Answer → Median
// 2️⃣ Weighted Equalization
// minimize Σ |arr[i] - x| * weight[i]
// Answer → Weighted Median
// 3️⃣ Min Moves to Equal Array Elements
// LeetCode classic.
// 4️⃣ Post Office Problem (1D version)
// Place one facility minimizing weighted distances.
// 5️⃣ Min Cost to Make Array Equal (LeetCode 2448)
// Exactly same logic.

🧠 THE GOLDEN RULE
// ✅ Case 1: Only ONE array is given
// Example:
// nums = [1, 0, 0, 8, 6]
// And problem says:
// Minimize total moves
// You can increment/decrement by 1
// Cost per unit = SAME for all elements
// Then formula is: ∑∣nums[i]−x∣
// 🔥 Use → Normal Median
// Because:
// Every element contributes equally (weight = 1)

// ✅ Case 2: TWO arrays are given

// Example:
// heights = [1,3,5]
// cost    = [2,4,1]
// And problem says:
// Cost to change height i by 1 unit = cost[i]
// Then formula is: ∑∣heights[i]−x∣×cost[i]
// 🔥 Use → Weighted Median
// Because:
// Each element has DIFFERENT influence.

// 🧠 Intuition Difference
// Normal Median
// Think:
// Everyone has equal voting power.
// Balance number of elements left and right.

// Weighted Median
// Think:
// Each element has voting power proportional to cost.
// Balance TOTAL WEIGHT left and right.


class Solution {
public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size();
        
        // Step 1: Pair height with cost
        vector<pair<int,int>> towers;
        for(int i = 0; i < n; i++) {
            towers.push_back({heights[i], cost[i]});
        }

        // Step 2: Sort by height
        sort(towers.begin(), towers.end());

        // Step 3: Calculate total weight
        long long totalWeight = 0;
        for(int i = 0; i < n; i++) {
            totalWeight += towers[i].second;
        }

        // Step 4: Find weighted median
        long long currWeight = 0;
        int targetHeight = 0;

        for(int i = 0; i < n; i++) {
            currWeight += towers[i].second;
            if(currWeight >= (totalWeight + 1) / 2) {
                targetHeight = towers[i].first;
                break;
            }
        }

        // Step 5: Calculate total cost
        long long minCost = 0;
        for(int i = 0; i < n; i++) {
            minCost += 1LL * abs(heights[i] - targetHeight) * cost[i];
        }

        return minCost;
    }
};


class Solution {
public:
    long long minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size();
        // Step 1: Pair height with cost
        vector<pair<int,int>> towers;
        for(int i = 0; i < n; i++) {
            towers.push_back({heights[i], cost[i]});
        }

        // Step 2: Sort by height
        sort(towers.begin(), towers.end());

        // Step 3: Calculate total weight
        long long totalWeight = 0;
        for(int i = 0; i < n; i++) {
            totalWeight += towers[i].second;
        }

        // Step 4: Find weighted median
        long long halfWeight  = (totalWeight + 1) / 2;
        long long currWeight = 0;
        int targetHeight = 0;

        for(int i = 0; i < n; i++) {
            currWeight += towers[i].second;

            if(currWeight >= halfWeight) {
                targetHeight = towers[i].first;
                break;
            }
        }

        // Step 5: Calculate total cost
        long long minCost = 0;
        for(int i = 0; i < n; i++) {
            minCost += 1LL * abs(heights[i] - targetHeight) * cost[i];
        }
        return minCost;
    }
};



class Solution {
public:
    long long minCost(vector<int>& heights, vector<int>& cost) {
        
        int n = heights.size();
        
        // Step 1: Pair height with cost
        vector<pair<int,int>> towers;
        for(int i = 0; i < n; i++) {
            towers.push_back({heights[i], cost[i]});
        }

        // Step 2: Sort by height
        sort(towers.begin(), towers.end());

        // Step 3: Calculate total weight
        long long totalWeight = 0;
        for(int i = 0; i < n; i++) {
            totalWeight += towers[i].second;
        }

        // Step 4: Find weighted median
        long long medianWeight = (totalWeight + 1) / 2;

        long long currWeight = 0;
        int targetHeight = 0;

        for(int i = 0; i < n; i++) {
            currWeight += towers[i].second;

            if(currWeight >= medianWeight) {
                targetHeight = towers[i].first;
                break;
            }
        }

        // Step 5: Calculate total cost
        long long minCost = 0;
        for(int i = 0; i < n; i++) {
            minCost += 1LL * abs(heights[i] - targetHeight) * cost[i];
        }

        return minCost;
    }
};


class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n=nums.size();
        // here cost is weights
        vector<pair<int,int>>towers;
        for(int i=0;i<n;i++){
            towers.push_back({nums[i],cost[i]});
        }
        
        sort(towers.begin(),towers.end());

        long long totalWeight=0;
        for(int i=0;i<n;i++){
            totalWeight+=towers[i].second;
        }

        long long halfWeight=(totalWeight+1)/2;
        long long target=0;
        long long currWeight=0;
        for(int i=0;i<n;i++){
           currWeight+=towers[i].second;
           if(currWeight>=halfWeight){
            target=towers[i].first;
            break;
           }
        }
        long long minCost=0;
        for(int i=0;i<n;i++){
            minCost+=1LL*abs(nums[i]-target)*cost[i];
        }
        return minCost;
    }
};


// 1️⃣ Make All Elements Equal
// Concept: Minimize
// ∑∣arr[i]−x∣
// Answer: Median
// 🔗 LeetCode 462 – Minimum Moves to Equal Array Elements II
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

// 2️⃣ Weighted Equalization
// Concept:
// ∑∣arr[i]−x∣×weight[i]
// Answer: Weighted Median
// 🔗 LeetCode 2448 – Minimum Cost to Make Array Equal
// https://leetcode.com/problems/minimum-cost-to-make-array-equal/
// (This is exactly the tower problem we solved.)

// 3️⃣ Min Moves to Equal Array Elements
// There are two famous versions:
// 🔹 Version 1 (Different concept – mathematical trick)
// 🔗 LeetCode 453 – Minimum Moves to Equal Array Elements
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
// 👉 Uses sum - min trick (not median).
// 🔹 Version 2 (Median based)
// 🔗 LeetCode 462 – Minimum Moves to Equal Array Elements II
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// 👉 Uses median.

// 4️⃣ Post Office Problem (1D)
// Concept: Place 1 facility minimizing total distance.
// 🔗 SPOJ – POSTERS / POSTOFFICE style problems
// https://www.spoj.com/problems/POSTERS/
// 🔗 Classic reference:
// “Post Office Problem” (Dynamic Programming version with k offices)
// https://leetcode.com/problems/allocate-mailboxes/
// LeetCode 1478 – Allocate Mailboxes
// 👉 When k = 1 → solution is median.

// 5️⃣ Min Cost to Make Array Equal (Weighted Version)
// 🔗 LeetCode 2448
// https://leetcode.com/problems/minimum-cost-to-make-array-equal/
// 🔥 Extra Important Median Problems (Must Practice)
// 🔹 LeetCode 296 – Best Meeting Point
// https://leetcode.com/problems/best-meeting-point/
// 👉 Uses median in 2D.
// 🔹 LeetCode 1703 – Minimum Adjacent Swaps for K Consecutive Ones
// https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/


// 👉 Uses median trick.
// 🎯 When You See These Keywords
// Minimize total absolute difference
// Make all elements equal
// Minimize total distance
// Equalize heights with cost
// Facility placement
// 👉 Think Median / Weighted Median