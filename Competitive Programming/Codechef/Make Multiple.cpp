#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long A, B;
    cin >> A >> B;

    long long D = B - A;

    if(D == 0){
        cout << "YES\n";
        return;
    }

    // check if any divisor of D is >= A
    for(long long i = 1; i * i <= D; i++){
        if(D % i == 0){
            long long d1 = i;
            long long d2 = D / i;

            if(d1 >= A || d2 >= A){
                cout << "YES\n";
                return;
            }
        }
    }

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


#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long A, B;
    cin >> A >> B;
    if (A == B || (B - A) >= A) {
        cout << "YES\n";
    } else {
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
}
