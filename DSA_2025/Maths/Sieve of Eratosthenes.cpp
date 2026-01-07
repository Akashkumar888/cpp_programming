
// 5️⃣ Sieve of Eratosthenes (Prime up to N) 🔥

vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}


// ⏱️ O(n log log n)
// ✔ Best for range prime queries