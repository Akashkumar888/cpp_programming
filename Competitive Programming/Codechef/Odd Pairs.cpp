#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin>>n;
    // two different odd number sum is even
    // two different even number sum is even
    // two number sum if odd if one number is odd and one number is even 
    long long oddNumbers=(n/2)+(n%2);
    long long evenNumber=n - oddNumbers;
    // 🔥 valid pairs:
    // (odd, even) + (even, odd)
    // so multiply by 2
    cout<<(oddNumbers*evenNumber)*2<<endl;
}
int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
// ⚡ Why multiply?
// 👉 Choose:
// 1 odd number
// 1 even number
// odd * even
// 👉 But pairs are:
// (odd, even)
// (even, odd)
// 👉 So multiply by 2
// total = odd * even * 2

// 🧠 PARITY RULES (ODD / EVEN)
// ➤ 1. SUM (A + B)
// // even + even = even
// // odd + odd = even
// // even + odd = odd
// // odd + even = odd

// // 👉 sum is odd only when:
// // one is odd and one is even
// ➤ 2. DIFFERENCE (A - B)
// // even - even = even
// // odd - odd = even
// // even - odd = odd
// // odd - even = odd

// // 👉 difference is odd only when:
// // one is odd and one is even

// 👉 Same rule as sum ✅

// ➤ 3. MULTIPLICATION (A * B)
// // even * even = even
// // even * odd = even
// // odd * even = even
// // odd * odd = odd

// // 👉 multiplication is odd only when:
// // both numbers are odd
// ➤ 4. DIVISION (A / B) (integer division case ⚠️)

// 👉 This is tricky — depends on divisibility

// // odd / odd = can be odd or even (depends)
// // even / odd = even
// // even / even = can be odd or even
// // odd / even = not integer (ignore in most CP problems)

// 👉 In CP, we usually don’t rely on parity for division unless clearly divisible
