#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v(5);
    for(int i=0;i<5;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end()); //o(n*log(n))
    sort(v.rbegin(),v.rend()); //o(n*log(n))
    for(int i=0;i<5;i++){
        cout<<v[i]<<" ";;;;; // ek line ek se jyda semicolon de sakte ho not error
    }
    return 0;
}