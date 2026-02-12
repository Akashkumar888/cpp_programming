
class Solution {
public:
// number of distinct even numbers in the subarray is equal to the number of distinct odd numbers.
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> evenSet;
            unordered_set<int> oddSet;
            for (int j = i; j < n; j++) {
                int val = nums[j];
                if (val % 2 == 0)evenSet.insert(val);
                else oddSet.insert(val);
                if (evenSet.size() == oddSet.size()) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};