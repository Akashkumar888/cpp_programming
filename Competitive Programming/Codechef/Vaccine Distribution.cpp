#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n,d;
    cin>>n>>d;

    int risk=0;
    int normal=0;

    for(int i=0;i<n;i++){

        int age;
        cin>>age;

        if(age<=9 || age>=80){
            risk++;
        }
        else{
            normal++;
        }
    }

    int daysRisk=(risk+d-1)/d;
    int daysNormal=(normal+d-1)/d;

    cout<<daysRisk+daysNormal<<"\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
