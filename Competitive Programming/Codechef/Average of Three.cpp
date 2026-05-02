#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int sum=n*3;
    cout<<1<<" "<<2<<" "<<sum-3<<" "<<"\n";
}
int main() {
	// your code goes here
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}


#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x;
    cin >> x;

    cout << x-1 << " " << x << " " << x+1 << "\n";
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
