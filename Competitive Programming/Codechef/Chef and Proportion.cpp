#include <bits/stdc++.h>
using namespace std;

void solve(){
    vector<int> v(4);
    for(int i = 0; i < 4; i++) cin >> v[i];

    sort(v.begin(), v.end());

    do {
        int x = v[0], y = v[1], z = v[2], w = v[3];

        if(x * w == y * z){
            cout << "Possible\n";
            return;
        }

    } while(next_permutation(v.begin(), v.end()));

    cout << "Impossible\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    vector<int> v = {a,b,c,d};

    for(int i = 0; i < 4; i++){
        for(int j = i+1; j < 4; j++){
            vector<int> rest;
            for(int k = 0; k < 4; k++){
                if(k != i && k != j) rest.push_back(v[k]);
            }

            // check both orders
            if(v[i] * rest[1] == v[j] * rest[0] ||
               v[i] * rest[0] == v[j] * rest[1]){
                cout << "Possible\n";
                return;
            }
        }
    }

    cout << "Impossible\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
