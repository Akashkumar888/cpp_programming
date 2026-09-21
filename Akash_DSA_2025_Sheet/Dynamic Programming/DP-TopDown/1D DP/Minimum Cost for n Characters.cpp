
class Solution {
  public:

    int minCost(int n, int i, int d, int c) {

        const long long INF = 1e18;

        vector<long long> dp(n + 1, INF);

        // dp[x] = minimum cost to make exactly x characters

        dp[0] = 0;


        // Deque stores:
        // { value = dp[y] + 2*y*d, y }
        //
        // We need the minimum value for
        // ceil(x/2) <= y < x

        deque<pair<long long, int>> dq;


        for(int x = 1; x <= n; x++) {

            // y = x-1 becomes available
            int y = x - 1;

            if(y > 0) {

                long long value =
                    dp[y] + 2LL * y * d;


                // Maintain increasing values
                while(!dq.empty() &&
                      dq.back().first >= value) {

                    dq.pop_back();
                }


                dq.push_back({value, y});
            }


            // Valid y must satisfy:
            //
            // 2*y >= x
            //
            // y >= ceil(x/2)
            int low = (x + 1) / 2;


            // Remove y which are too small
            while(!dq.empty() &&
                  dq.front().second < low) {

                dq.pop_front();
            }


            // ------------------------------------------------
            // Option 1:
            // Insert one character
            // x-1 -> x
            // ------------------------------------------------

            dp[x] = dp[x - 1] + i;


            // ------------------------------------------------
            // Option 2:
            //
            // y -> 2*y using copy
            // 2*y -> x using deletion
            //
            // cost =
            // dp[y] + c + (2*y-x)*d
            //
            //      =
            // dp[y] + 2*y*d + c - x*d
            // ------------------------------------------------

            if(!dq.empty()) {

                long long copyDelete =
                    dq.front().first
                    + c
                    - 1LL * x * d;


                dp[x] = min(
                    dp[x],
                    copyDelete
                );
            }
        }


        return (int)dp[n];
    }
};