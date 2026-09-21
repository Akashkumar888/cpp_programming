class Solution {
  public:
    int MOD = 1e9 + 7;
    vector<long long> computeCatalan(int n) {
        vector<long long> catalan(n + 1, 0);
        catalan[0] = 1;

        // Catalan Formula:
        //
        // C[i] = C[0]*C[i-1]
        //      + C[1]*C[i-2]
        //      + ...
        //      + C[i-1]*C[0]

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                catalan[i] = (catalan[i] + (catalan[j] * catalan[i - j - 1]) % MOD) % MOD;
            }
        }
        return catalan;
    }
    int prefixStrings(int n) {
        // Number of prefix-balanced binary strings
        // is equal to nth Catalan number
        vector<long long> catalan = computeCatalan(n);
        return catalan[n];
    }
};





class Solution {
  public:
    const long long MOD = 1e9 + 7;
    long long power(long long a, long long b) {
        long long ans = 1;
        while (b > 0) {
            if (b % 2 == 1) {
                ans = (ans * a) % MOD;
            }
            a = (a * a) % MOD;
            b /= 2;
        }
        return ans;
    }
    int prefixStrings(int n) {
        // Need factorial till 2*n
        vector<long long> fact(2 * n + 1);
        fact[0] = 1;
        for (int i = 1; i <= 2 * n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        // Catalan(n)
        //
        // (2n)!
        // ----------------
        // n! * n! * (n+1)

        long long ans = fact[2 * n];
        ans = (ans * power(fact[n], MOD - 2)) % MOD;
        ans = (ans * power(fact[n], MOD - 2)) % MOD;
        ans = (ans * power(n + 1, MOD - 2)) % MOD;
        return ans;
    }
};



