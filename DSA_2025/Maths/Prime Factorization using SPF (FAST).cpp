
// 7️⃣ Prime Factorization using SPF (FAST)

vector<int> primeFactors(int n, vector<int>& spf) {
    vector<int> factors;
    while (n > 1) {
        factors.push_back(spf[n]);
        n /= spf[n];
    }
    return factors;
}


// 🔥 Used in:
// divisor count
// divisor sum
// number theory problems
