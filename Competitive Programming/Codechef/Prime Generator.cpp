#include <bits/stdc++.h>
using namespace std;

// base sieve up to sqrt(n)
vector<int> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) primes.push_back(i);
    }

    return primes;
}

void solve(){
    int m, n;
    cin >> m >> n;

    int limit = sqrt(n);
    vector<int> primes = sieve(limit);

    vector<bool> isPrime(n - m + 1, true);

    // handle case when m = 1
    if (m == 1) isPrime[0] = false;

    for (int p : primes) {
        int start = max(p * p, ((m + p - 1) / p) * p);

        for (int j = start; j <= n; j += p) {
            isPrime[j - m] = false;
        }
    }

    for (int i = m; i <= n; i++) {
        if (isPrime[i - m]) {
            cout << i << endl;
        }
    }

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
