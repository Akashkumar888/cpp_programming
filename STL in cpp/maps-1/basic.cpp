#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,string>m;
    m[1]="abc";
    m[5]="cdc";
    m[3]="ase";
    m.insert({6,"efg"});
    map<int,string> :: iterator it;
    for(it =m.begin();it!=m.end();it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    return 0;
}