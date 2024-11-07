#include<bits/stdc++.h>
using namespace std;
void akash(unordered_set<string>&m){
cout<<"size: "<<m.size()<<endl;
for(auto it=m.begin();it!=m.end();it++){
    cout<<(*it)<<endl;
}
}
int main(){
    unordered_set<string>s;
    s.insert("akash"); // o(1)
    s.insert("qwerty");
    s.insert("asdf");
    s.insert("pasdfgh");
    akash(s);
    return 0;
}