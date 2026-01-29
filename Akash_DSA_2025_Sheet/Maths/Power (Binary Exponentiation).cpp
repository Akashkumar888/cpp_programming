
// 🔟 Power (Binary Exponentiation)

long long power(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}


// ⏱️ O(log n)