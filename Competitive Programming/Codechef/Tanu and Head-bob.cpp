#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int countI=0;
    int countN=0;
    int countY=0;
    for(int i=0;i<n;i++){
        if(s[i]=='I'){
            countI++;
        }
        else if(s[i]=='N')countN++;
        else countY++;
    }
    if(countI>0)cout<<"INDIAN"<<endl;
    else if(countN==n)cout<<"NOT SURE"<<endl;
    else cout<<"NOT INDIAN"<<endl;
}
int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
