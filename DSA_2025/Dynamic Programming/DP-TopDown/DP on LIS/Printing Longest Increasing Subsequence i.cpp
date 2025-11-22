
class Solution {
  public:
    int printingLIS(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> prevIndex(n,-1);
        int maxi = 1;
        int last_idx = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    prevIndex[i] = j;
                 }
                }
            }
            if(maxi<dp[i]){
               maxi =dp[i];
               last_idx = i;
            }
        }

        // Reconstruct LIS
        vector<int> result;
        while (last_idx != -1) {
            result.push_back(arr[last_idx]);
            last_idx = prevIndex[last_idx];
        }

        reverse(result.begin(), result.end()); // Correct order

        // PRINT LIS
        cout << "LIS elements: ";
        for (int x : result) cout << x << " ";
        cout << endl;

        return maxi; // length of LIS
    }
}; 