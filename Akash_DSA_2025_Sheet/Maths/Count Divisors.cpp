
// 3️⃣ Count Divisors (Without Storing)

int countDivisors(int n) {
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            if (i != n / i) cnt++;
        }
    }
    return cnt;
}


// ⏱️ O(√n)
// ✔ Faster than storing vector