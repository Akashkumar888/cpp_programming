#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    set<int> st;

    // store distinct non-zero heights
    for(int &num : arr){

        if(num != 0){
            st.insert(num);
        }
    }

    cout << st.size() << "\n";
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
