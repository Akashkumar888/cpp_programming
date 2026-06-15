#include <bits/stdc++.h>
using namespace std;

void solve(){

    long long H, X, Y1, Y2, K;
    cin >> H >> X >> Y1 >> Y2 >> K;

    long long gunHits = (H + X - 1) / X;

    long long laserHits;

    long long hitsWithHighDamage = (H + Y1 - 1) / Y1;

    if(hitsWithHighDamage <= K){

        laserHits = hitsWithHighDamage;
    }
    else{

        long long damage = K * Y1;

        long long remaining = H - damage;

        long long extraHits =
            (remaining + Y2 - 1) / Y2;

        laserHits = K + extraHits;
    }

    cout << min(gunHits, laserHits) << "\n";
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
