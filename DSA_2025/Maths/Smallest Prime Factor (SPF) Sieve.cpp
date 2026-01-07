
// 6️⃣ Smallest Prime Factor (SPF) Sieve 🔥🔥

vector<int> smallestPrimeFactor(int n) {
    vector<int> spf(n + 1);
    for (int i = 1; i <= n; i++)
        spf[i] = i;

    for (int i = 2; i * i <= n; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
    return spf;
}


// ✔ Preprocessing: O(n log log n)
// ✔ Factorization in O(log n)