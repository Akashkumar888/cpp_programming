#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll modularExponentiation(ll base, ll exponent, ll mod) {
    ll result = 1;
    base = base % mod; // Take modulo of base
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}

ll initialv(ll a, ll b, ll c) {
    return (modularExponentiation(b, a, c) + a % c) % c;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b, c;
        cin >> a >> b >> c;
        cout << initialv(a, b, c) << " " << modularExponentiation(b, a, c) << endl;
    }
    return 0;
}
