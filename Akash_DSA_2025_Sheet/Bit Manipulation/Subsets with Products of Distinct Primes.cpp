
class Solution {
public:
    const int MOD = 1e9 + 7;

    int countSubsets(vector<int> &arr) {

        // First 10 primes <= 30
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29};

        // mask[x] = bitmask of prime factors
        // mask[x] = -1 means x contains repeated prime factors (invalid)
        vector<int> mask(31, -1);

        mask[1] = 0;

        // Precompute masks for numbers 2...30
        for(int num = 2; num <= 30; num++) {

            int x = num;
            int currMask = 0;
            bool valid = true;

            for(int i = 0; i < 10; i++) {

                int cnt = 0;

                while(x % primes[i] == 0) {
                    x /= primes[i];
                    cnt++;
                }

                if(cnt > 1) {
                    valid = false;
                    break;
                }

                if(cnt == 1)
                    currMask |= (1 << i);
            }

            if(valid)
                mask[num] = currMask;
        }

        vector<int> dp(1 << 10, 0);
        dp[0] = 1;

        int ones = 0;

        for(int num : arr) {

            if(num == 1) {
                ones++;
                continue;
            }

            if(mask[num] == -1)
                continue;

            int currMask = mask[num];

            for(int oldMask = (1 << 10) - 1; oldMask >= 0; oldMask--) {

                if(dp[oldMask] == 0)
                    continue;

                if((oldMask & currMask) == 0) {

                    dp[oldMask | currMask] =
                        (dp[oldMask | currMask] + dp[oldMask]) % MOD;
                }
            }
        }

        long long waysForOnes = 1;

        while(ones--) {
            waysForOnes = (waysForOnes * 2) % MOD;
        }

        long long ans = 0;

        // Ignore mask 0 (empty subset or subsets containing only 1's)
        for(int m = 1; m < (1 << 10); m++) {
            ans = (ans + dp[m]) % MOD;
        }

        ans = (ans * waysForOnes) % MOD;

        return (int)ans;
    }
};