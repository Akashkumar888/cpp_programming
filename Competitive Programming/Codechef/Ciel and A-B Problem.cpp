#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,b;
    cin>>a>>b;
    int value = a - b;
    int last = value % 10;

    if(last != 9)value = value - last + 9;
    else value = value - last + 8;

    cout << value << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
