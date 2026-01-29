
class Solution {
public:
    // Generate all subset sums in range [l, r)
    void genSums(int idx, int end, long long sum,vector<int>& arr, vector<long long>& out) {
        if (idx == end) {
            out.push_back(sum);
            return;
        }
        genSums(idx + 1, end, sum, arr, out);            // not pick
        genSums(idx + 1, end, sum + arr[idx], arr, out); // pick
    }
    int lowerBound(vector<long long>& arr, long long target) {
        int l = 0, r = arr.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        if (n == 1)return min(abs(goal), abs(nums[0] - goal));
        int mid = n / 2;

        // Step 1 & 2: generate all subset sums of both halves
        vector<long long> firstHalf , secondHalf; 
        genSums(0, mid, 0, nums, firstHalf);
        genSums(mid, n, 0, nums, secondHalf);

        // Step 3: sort second half for binary search
        sort(secondHalf.begin(), secondHalf.end());

        long long ans = LLONG_MAX;

        for (long long &x : firstHalf) {
            long long need = goal - x;
            int idx = lowerBound(secondHalf, need);

            if (idx < secondHalf.size())
                ans = min(ans, abs(goal - (x + secondHalf[idx])));
            if (idx > 0)
                ans = min(ans, abs(goal - (x + secondHalf[idx - 1])));
        }
        return (int)ans;
    }
};
