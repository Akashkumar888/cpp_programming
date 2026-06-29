#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    int chef = 0;
    int chefina = 0;

    int lose = 0;
    int draw = 0;

    for(int i = 0; i < n; i++){

        if(a[i] == b[i]){

            draw++;
        }
        else if(
            (a[i] == 'R' && b[i] == 'S') ||
            (a[i] == 'S' && b[i] == 'P') ||
            (a[i] == 'P' && b[i] == 'R')
        ){

            chef++;
        }
        else{

            chefina++;
            lose++;
        }
    }

    if(chef > chefina){

        cout << 0 << "\n";
        return;
    }

    int diff = chefina - chef;

    int changes = 0;

    while(diff >= 0 && lose > 0){

        diff -= 2;
        lose--;
        changes++;
    }

    while(diff >= 0 && draw > 0){

        diff -= 1;
        draw--;
        changes++;
    }

    if(diff >= 0){

        cout << -1 << "\n";
    }
    else{

        cout << changes << "\n";
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

    return 0;
}
