#include<bits/stdc++.h>
using namespace std;
void akash(multiset<string>&m){
    cout<<m.size()<<endl;
    for(auto it:m) cout<<(it)<<endl;
}
int main(){
    multiset<string>s;
    s.insert("asdf"); //o(log(n))
    s.insert("qwer");
    s.insert("qsdf");
    s.insert("azxcv");
    s.insert("qwer");
    s.insert("wdfty");
    s.insert("qsdf");
    s.erase("qwer");
    akash(s);
    return 0;
}