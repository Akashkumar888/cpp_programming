#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int bit = floor(log2(n)+1);
    int m=1<<(bit-1);
    m=m|m-1;
    cout<<(m^n)<<endl;
    return 0;
}