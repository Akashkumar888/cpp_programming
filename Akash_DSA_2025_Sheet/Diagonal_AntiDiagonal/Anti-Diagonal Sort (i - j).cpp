
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> mat[i][j];

    map<int, vector<int>> mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mp[i-j].push_back(mat[i][j]);
        }
    }

    for(auto &p: mp) sort(p.second.begin(), p.second.end());

    cout << "Anti-Diagonal Sort (i-j):\n";
    for(auto &p: mp){
        for(int x: p.second) cout << x << " ";
        cout << "\n";
    }
}

