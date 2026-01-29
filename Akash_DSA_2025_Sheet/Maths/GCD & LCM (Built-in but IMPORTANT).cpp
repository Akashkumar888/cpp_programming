
// 9️⃣ GCD & LCM (Built-in but IMPORTANT)

int gcd(int a, int b) {
    return __gcd(a, b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}