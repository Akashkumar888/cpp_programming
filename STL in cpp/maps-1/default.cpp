#include<bits/stdc++.h>
using namespace std;
void akash(map<int,int>&m){
    cout<<m.size()<<endl;
  for(auto &it:m){
        cout<<(it).first<<" "<<(it).second<<endl;
    }
}
int main(){
    map<int,int>m;
    // m[1]="abc"; // o(log(n))
    // m[5]="cdc";
    // m[3]="ase";
    // m.insert({6,"efg"});
    m[7];
    m[8];
    m[9];
    m[10];
    m[11];
    akash(m);
    return 0;
}