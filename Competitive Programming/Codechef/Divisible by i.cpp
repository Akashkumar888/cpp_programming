#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    int left = 1, right = n;
    
    // Fill the array from the end to the beginning
    for (int i = n - 1; i >= 0; i -= 2) {
        p[i] = left++;
        if (i - 1 >= 0) {
            p[i - 1] = right--;
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << p[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
