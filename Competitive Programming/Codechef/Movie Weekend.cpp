#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n), brr(n);

    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) cin >> brr[i];

    int idx = 1;

    int maxProduct = arr[0] * brr[0];
    int maxRating = brr[0];

    for(int i = 1; i < n; i++){

        int product = arr[i] * brr[i];

        // larger product
        if(product > maxProduct){

            maxProduct = product;
            maxRating = brr[i];
            idx = i + 1;
        }

        // same product -> higher rating
        else if(product == maxProduct && brr[i] > maxRating){
                maxRating = brr[i];
                idx = i + 1;
        }
    }
    cout << idx << "\n";
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
