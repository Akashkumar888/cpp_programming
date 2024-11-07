#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,string>m;
    m[1]="abc";
    m[5]="cdc";
    m[3]="ase";
    m.insert({6,"efg"});
    for(auto it:m){
        cout<<(it).first<<" "<<(it).second<<endl;
    }
    return 0;
}