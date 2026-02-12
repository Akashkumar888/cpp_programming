// 🧠 THE GOLDEN RULE
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
    int minMoves2(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int median = nums[n / 2];   // normal median

        long long totalCost = 0;
        for(int i = 0; i < n; i++) {
            totalCost += abs(nums[i] - median);
        }

        return totalCost;
    }
};

