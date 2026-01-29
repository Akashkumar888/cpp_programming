
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 2) {
        cout << "Not Prime";
        return 0;
    }

    vector<bool> isPrime(n + 1, true);

    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    if (isPrime[n])cout << "True";
    else cout << "False";

    return 0;
}
