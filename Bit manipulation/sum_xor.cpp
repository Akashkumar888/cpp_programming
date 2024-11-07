#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    int total=floor(log2(n)+1);
    int setbits=__builtin_popcountll(n);
    int unsetbits=total-setbits;
    cout<<(1ll<<unsetbits)<<endl;
    return 0;
}