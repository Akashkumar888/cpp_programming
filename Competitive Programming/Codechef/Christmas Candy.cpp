#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;

    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int maxSeen=arr[0];

    int count=0;

    for(int i=1;i<n;i++){

        if(arr[i] < maxSeen){

            count++;
        }
        else{

            maxSeen=arr[i];
        }
    }

    cout << count << "\n";
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
