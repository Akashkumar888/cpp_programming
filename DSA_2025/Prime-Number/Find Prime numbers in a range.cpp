
// User function Template for C++

class Solution {
  public:
  vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);

    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}
    vector<int> primeRange(int M, int N) {
        // code here
         vector<int> ans;

        // build sieve once till N
        vector<bool> isPrime = sieve(N);

        for (int i = M; i <= N; i++) {
            if (isPrime[i])
                ans.push_back(i);
        }
        return ans;
    }
};