
class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        int n = arr.size();
        long long ans = 0;
        // Check every bit
        for(int bit = 0; bit < 31; bit++) {
            int count = 0;
            // Count numbers having this bit set
            for(int i = 0; i < n; i++) {
                if(arr[i] & (1 << bit)) {
                    count++;
                }
            }
            // Number of pairs having this bit set
            long long pairs = 1LL * count * (count - 1) / 2;
            // Contribution of this bit
            ans += pairs * (1LL << bit);
        }
        return ans;
    }
};