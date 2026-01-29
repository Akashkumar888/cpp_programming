
// 2️⃣ All Factors of a Number (√n) ✅ (You already used this)

vector<int> factors(int n) {
    vector<int> res;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i)
                res.push_back(n / i);
        }
    }
    return res;
}


// ⏱️ O(√n)
