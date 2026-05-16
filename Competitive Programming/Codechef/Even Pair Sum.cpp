#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long a,b;
    cin>>a>>b;
    // odd + odd = even 
    // even + even = even
    long long odd_A,even_A;
    long long odd_B,even_B;
    if(a%2){// odd
         even_A=a/2;
         odd_A=a/2 + 1;
    }
    if(a%2==0){
         even_A=a/2;
         odd_A=a/2;
    }
    if(b%2){
        even_B=b/2;
        odd_B=b/2 +1;
    }
    if(b%2==0){
        even_B=b/2;
        odd_B=b/2;
    }
    cout<<(odd_A*odd_B+even_A*even_B)<<"\n";
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

    long long a, b;
    cin >> a >> b;

    long long evenA = a / 2;
    long long oddA  = a - evenA;

    long long evenB = b / 2;
    long long oddB  = b - evenB;

    long long answer =
        (oddA * oddB) +
        (evenA * evenB);

    cout << answer << "\n";
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
