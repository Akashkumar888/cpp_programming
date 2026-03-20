class Solution {
public:
// 3 or more.
    bool isPossible(vector<int>& nums) {
        int k=3;//All subsequences have a length of 3 or more.
        map<int, int> count, end;
        for (int &num : nums) count[num]++;

        for (int &num : nums) {
            if (count[num] == 0) continue;

            count[num]--;

            // Try to extend an existing subsequence ending at num-1
            if (end[num - 1] > 0) {
                end[num - 1]--;
                end[num]++;
            }
            // Try to start a new subsequence [num, num+1, num+2]
            else if (count[num + 1] > 0 && count[num + 2] > 0) {
                count[num + 1]--;
                count[num + 2]--;
                end[num + 2]++;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
// ✅ Conclusion
// If the problem says “split into groups of exactly k consecutive numbers” → use isPossibleDivide / isNStraightHand style.
// If the problem says “split into subsequences of length ≥ k” → use heap-based or map-based greedy approach (tracking end[num]).