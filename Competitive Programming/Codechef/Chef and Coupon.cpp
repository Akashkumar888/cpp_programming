#include <bits/stdc++.h>
using namespace std;

void solve(){

    int d, c;
    cin >> d >> c;

    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;

    int b1, b2, b3;
    cin >> b1 >> b2 >> b3;

    int day1 = a1 + a2 + a3;
    int day2 = b1 + b2 + b3;

    int withoutCoupon = day1 + day2 + 2 * d;

    int withCoupon = day1 + day2 + c;

    if(day1 < 150){
        withCoupon += d;
    }

    if(day2 < 150){
        withCoupon += d;
    }

    if(withCoupon < withoutCoupon){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
