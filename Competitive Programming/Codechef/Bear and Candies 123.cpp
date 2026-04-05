#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a, b;
    cin >> a >> b;
    int i = 1; 
    while (true) {
        if (a < i) {
            cout << "Bob"<<endl;
            return;
        }
        a -= i;
        i++;

        if (b < i) {
            cout << "Limak"<<endl;
            return;
        }
        b -= i;
        i++;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
