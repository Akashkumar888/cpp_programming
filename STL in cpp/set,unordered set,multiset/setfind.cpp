#include<bits/stdc++.h>
using namespace std;
void akash(set<string>&m){
cout<<"size: "<<m.size()<<endl;
for(auto it=m.begin();it!=m.end();it++){
    cout<<(*it)<<endl;
}
}
int main(){
    set<string>s;
    s.insert("akash"); // log(n)
    s.insert("qwerty");
    s.insert("pasdfgh");
    auto it=s.find("akash");
    if(it!=s.end()) cout<<(*it);
    return 0;
}