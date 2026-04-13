#include <bits/stdc++.h>
using namespace std;

// 🧠 💡 Queen Attack Logic
// Queen attacks in 8 directions:
// ➤ 1. Row (left + right)
// Left: y - 1
// Right: n - y
// ➤ 2. Column (up + down)
// Up: x - 1
// Down: n - x

// ➤ 3. Diagonals (4 directions)
// ↖ Top-Left
// 👉 min(x - 1, y - 1)
// ↗ Top-Right
// 👉 min(x - 1, n - y)
// ↙ Bottom-Left
// 👉 min(n - x, y - 1)
// ↘ Bottom-Right
// 👉 min(n - x, n - y)

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    int row = (y - 1) + (n - y);
    int col = (x - 1) + (n - x);

    int d1 = min(x - 1, y - 1);     // top-left
    int d2 = min(x - 1, n - y);     // top-right
    int d3 = min(n - x, y - 1);     // bottom-left
    int d4 = min(n - x, n - y);     // bottom-right

    int ans = row + col + d1 + d2 + d3 + d4;

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
