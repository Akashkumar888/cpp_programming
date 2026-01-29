// ⭐ Correct Logic (Guaranteed Accepted for Infosys OA)
// DP state:
// dp[i][x] = longest non-decreasing subsequence ending at index i with XOR = x

// Transition:
// For all j < i:
// If nums[j] ≤ nums[i]:
// dp[i][x ^ nums[i]] = max(dp[i][x ^ nums[i]], dp[j][x] + 1)

// Answer:
// Loop all dp[i][x] for x ≥ M and take max.


// ✅ Correct statement

// The maximum possible XOR between any two numbers depends on the number of bits, not the maximum value itself.
// If the max element = maxA, then the maximum XOR is:

// 👉 XOR maximum range = 2^(number_of_bits_in_maxA) - 1
// ⭐ Correct Statement
// If the maximum value in the array is maxA, and it uses k bits, then:
// ✔ Maximum possible XOR value is 2^k−1
// ⭐ Why This Is Correct?
// If a number needs k bits, it lies in this range:0≤x<2k
// XOR of any two such numbers also lies in: 0≤(a⊕b)<2k
// So the maximal XOR is:(111...111)binary​=2k−1
// ✔ This is the highest number representable using k bits,
// ✔ and XOR cannot exceed this.



class Solution {
public:
    int get_ans(int N, int M, vector<int>& A) {

        // compute maximum XOR limit dynamically
        int maxA = 0;
        for(int &v : A) maxA = max(maxA, v);

        //         ⭐ General rule
        // If max(A) < 2^k, then maximum XOR < 2^k.

        // This is why the correct dynamic maxX is:

        // int maxX = 1;
        // while(maxX <= maxA) maxX <<= 1;

        // This gives the next power of 2, which covers all XOR results.
        int maxX = 1;
        while(maxX <= maxA) maxX <<= 1;  // next power of 2

        // dp[i][x] = longest non-decreasing subsequence ending at i with XOR = x
        vector<vector<int>> dp(N, vector<int>(maxX, 0));

        int ans = 0;

        for(int i = 0; i < N; i++) {

            dp[i][A[i]] = 1;

            for(int j = 0; j < i; j++) {
                if(A[j] <= A[i]) {

                    for(int x = 0; x < maxX; x++) {
                        if(dp[j][x] > 0) {
                            int newX = x ^ A[i];
                            dp[i][newX] = max(dp[i][newX], dp[j][x] + 1);
                        }
                    }
                }
            }

            for(int x = M; x < maxX; x++) {
                ans = max(ans, dp[i][x]);
            }
        }

        return ans;
    }
};
