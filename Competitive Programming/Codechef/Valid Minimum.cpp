#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x, y, z;
    cin >> x >> y >> z;

    int mn = min({x, y, z});

    int count = 0;
    if(x == mn) count++;
    if(y == mn) count++;
    if(z == mn) count++;

    if(count >= 2)
        cout << "YES\n";
    else
        cout << "NO\n";
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


// ⚔️ endl vs "\n"
// ✅ 1. endl
// cout << "Hello" << endl;
// What it does:
// Prints newline ✅
// Flushes output buffer ❗ (very important)
// ✅ 2. "\n"
// cout << "Hello\n";
// What it does:
// Prints newline ✅
// Does NOT flush buffer ❌
// 🚀 Key Difference
// Feature	endl	"\n"
// New line	✅	✅
// Flush buffer	✅	❌
// Speed	❌ Slow	✅ Fast
// ⚡ Why endl is Slow
// 👉 Every time you use endl, it forces:
// flush output buffer → send data immediately to console
// 👉 This is expensive operation ❌
// 🧠 Why "\n" is Fast
// 👉 Output stays in buffer and prints in bulk:
// Buffered output → fewer system calls → faster
// 🔥 In Competitive Programming
// ❌ Avoid:
// cout << x << endl;
// ✅ Use:
// cout << x << "\n";
// ⚠️ When to Use endl?
// Use only when you need immediate output:
// Examples:
// Interactive problems (Codeforces interactive)
// Debugging real-time logs
// 🧪 Example (Performance)
// for(int i = 0; i < 1e6; i++){
//     cout << i << endl;   // VERY SLOW ❌
// }
// for(int i = 0; i < 1e6; i++){
//     cout << i << "\n";   // FAST ✅
// }
// 👉 Difference can be TLE vs AC 🚨
// 🎯 Final Recommendation
// 👉 In CP / DSA:
// Always use "\n" instead of endl
// 💬 Interview Answer (Short
// “endl flushes the buffer making it slower, while \n just adds a newline and is faster, so we prefer \n in competitive programming.”
// 🚀 Bonus Tip (You already use it 👍)
// ios::sync_with_stdio(false);
// cin.tie(NULL);
// 👉 This + "\n" = 🚀 maximum speed
