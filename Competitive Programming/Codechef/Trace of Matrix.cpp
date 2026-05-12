#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }

    int maxValue = 0;

    /*
        Every square submatrix trace
        lies on some diagonal.

        So check all diagonals.
    */

    // start from every row of first column
    for(int row = 0; row < n; row++){

        int i = row;
        int j = 0;

        int sum = 0;

        while(i < n && j < n){

            sum += mat[i][j];

            maxValue = max(maxValue, sum);

            i++;
            j++;
        }
    }

    // start from every column of first row
    // start from col = 1 because (0,0)
    // already covered
    for(int col = 1; col < n; col++){

        int i = 0;
        int j = col;

        int sum = 0;

        while(i < n && j < n){

            sum += mat[i][j];

            maxValue = max(maxValue, sum);

            i++;
            j++;
        }
    }

    cout << maxValue << "\n";
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
