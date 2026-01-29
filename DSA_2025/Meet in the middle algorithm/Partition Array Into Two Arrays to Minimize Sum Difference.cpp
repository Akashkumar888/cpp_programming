
class Solution {
public:
    // generate subset sums with count
    void genSums(int idx, int end, long long sum, int cnt,
                 vector<int>& arr, vector<vector<long long>>& out) {
        if (idx == end) {
            out[cnt].push_back(sum);
            return;
        }
        // not pick
        genSums(idx + 1, end, sum, cnt, arr, out);
        // pick
        genSums(idx + 1, end, sum + arr[idx], cnt + 1, arr, out);
    }

    // your own lower_bound
    int lowerBound(vector<long long>& arr, long long target) {
        int l = 0, r = arr.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return l;   // first index where arr[idx] >= target
    }

    int minimumDifference(vector<int>& nums) {
        int N = nums.size();        // = 2*n
        int n = N / 2;

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        // sumLeft[i] = all subset sums of left picking i elements
        // sumRight[i] = all subset sums of right picking i elements
        vector<vector<long long>> sumLeft(n + 1), sumRight(n + 1);

        genSums(0, n, 0, 0, left, sumLeft);
        genSums(0, n, 0, 0, right, sumRight);

        for (int i = 0; i <= n; i++)
            sort(sumRight[i].begin(), sumRight[i].end());

        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        long long ans = LLONG_MAX;

        // pick k from left and (n-k) from right
        for (int k = 0; k <= n; k++) {
            for (long long sl : sumLeft[k]) {
                auto &vec = sumRight[n - k];
                long long need = totalSum / 2 - sl;

                int idx = lowerBound(vec, need);

                if (idx < vec.size()) {
                    long long s = sl + vec[idx];
                    ans = min(ans, llabs(totalSum - 2 * s));
                }
                if (idx > 0) {
                    long long s = sl + vec[idx - 1];
                    ans = min(ans, llabs(totalSum - 2 * s));
                }
            }
        }
        return (int)ans;
    }
};
