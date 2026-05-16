
class Solution {
public:
    bool backtrack(int n,vector<int>& nums, vector<bool>& visited, int k, int start, int currSum, int target){
        // If only 1 subset left → always valid
        if(k == 1) return true;

        // If one subset completed
        if(currSum == target){
            // start next subset
            return backtrack(n,nums, visited, k-1, 0, 0, target);
        }

        for(int i = start; i < n; i++){
            if(visited[i]) continue;

            if(currSum + nums[i] > target) continue;

            visited[i] = true;

            if(backtrack(n,nums, visited, k, i+1, currSum + nums[i], target))return true;

            visited[i] = false; // backtrack

            // ⚡ Optimization (skip duplicates)
            if(currSum == 0) return false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int totalSum = 0;
        for(int &x : nums) totalSum += x;

        if(totalSum % k != 0) return false;

        int target = totalSum / k;

        // Sort descending (important optimization)
        sort(nums.rbegin(), nums.rend());

        vector<bool> visited(n, false);

        return backtrack(n,nums, visited, k, 0, 0, target);
    }
};