#include<bits/stdc++.h>
using namespace std;
void akash(multimap<int,string>&m1){
    cout<<m1.size()<<endl;
  for(auto &it:m1){
        cout<<(it).first<<" "<<(it).second<<endl;
    }
}
int main(){
    multimap<int,string>m1 = {
    {1,"abc"}, // o(log(n))
    {5,"cdc"},
    {3,"ase"},
    {5,"qwerty"},
    {3,"asdgf"}
    };
    m1.insert({6,"efg"});
    m1.insert(make_pair(7,"rfg"));
    akash(m1);
    return 0;
}