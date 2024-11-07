#include<bits/stdc++.h>
using namespace std;
int main(){
    set<string>s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        s.insert(str);
    }
    cout<<endl;
    for(auto it=s.begin();it!=s.end();it++){
        cout<<(*it)<<endl;
    }
    return 0;
}