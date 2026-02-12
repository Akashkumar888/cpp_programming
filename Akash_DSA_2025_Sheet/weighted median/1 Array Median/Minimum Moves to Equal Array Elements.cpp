
// 🚨 First Understand The Difference
// 🔹 Problem 462
// Minimum Moves to Equal Array Elements II
// Operation:
// You can increment OR decrement ANY element by 1.
// Formula becomes: ∑∣nums[i]−x∣
// 👉 Solution = Median
// 🔹 Problem 453
// Minimum Moves to Equal Array Elements
// Operation:
// In one move, you increment (n - 1) elements by 1.

// ⚠️ This is NOT the same operation.
// 🧠 Trick Behind 453 (Very Important)
// If you increment (n-1) elements by 1,
// That is mathematically equivalent to:
// 👉 Decrementing ONE element by 1.
// Why?
// Because:
// If you increase all except one,
// that one becomes relatively smaller.
// So instead of increasing n-1 elements,
// we can think:
// Decrease the maximum element.
// 🎯 Key Insight for 453
// To make all equal,
// we should bring everything down to the minimum element.
// Why?
// Because decreasing is equivalent to incrementing others.
// ✅ Formula for 453
// Minimum moves: ∑(nums[i]−minimum)

class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int minElement = *min_element(nums.begin(), nums.end());
        
        long long moves = 0;
        
        for(int i = 0; i < nums.size(); i++){
            moves += nums[i] - minElement;
        }
        
        return moves;
    }
};
