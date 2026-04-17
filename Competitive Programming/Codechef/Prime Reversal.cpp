#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    // if(s1==s2){
    //     cout<<"YES"<<endl;
    //     return;
    // }   
    int count1=0;
    int count2=0;
    for(int i=0;i<n;i++){
        if(s1[i]=='1')count1++;
        if(s2[i]=='1')count2++;
    }
    if(count1==count2){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}
int main() {
	// your code goes here
   int t;
   cin>>t;
   while(t--){
       solve();
   }
    return 0;
}
