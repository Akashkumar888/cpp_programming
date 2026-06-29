
class Solution {
  public:
    int maxPeopleDefeated(int p) {
        int l = 0;
        int r = 10000;
        int ans = 0;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            long long sum = 1LL * mid * (mid + 1) * (2LL * mid + 1) / 6;
            if(sum <= p) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
};