
// 1️⃣1️⃣ Modulo Power (Very Common)

long long modPow(long long a, long long b, long long mod) {
    long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
