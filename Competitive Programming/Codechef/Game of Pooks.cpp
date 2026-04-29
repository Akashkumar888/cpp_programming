#include <bits/stdc++.h>
using namespace std;

int main() {
    // Faster I/O
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;

        // Handle the special cases for N=2 and N=3
        if (n == 2 || n == 3) {
            cout << n - 1 << '\n';
        } 
        // For N=1 and N >= 4, the answer is N
        else {
            cout << n << '\n';
        }
    }

    return 0;
}
