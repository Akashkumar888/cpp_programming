#include<bits/stdc++.h>
using namespace std;
void akash(map<int,string>&m){
    cout<<m.size()<<endl;
  for(auto &it:m){
        cout<<(it).first<<" "<<(it).second<<endl;
    }
}
int main(){
    map<int,string>m;
    m[1]="abc"; // o(log(n))
    m[5]="cdc";
    m[3]="ase";
    m.insert({6,"efg"});
    akash(m);
    return 0;
}