#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,int>mp;
    pair<string,int>p1;
    p1.first="Akash";
    p1.second=12;
    pair<string,int>p2;
    p2.first="Surya";
    p2.second=34;
    pair<string,int>p3;
    p3.first="Ankit";
    p3.second=56;
    mp.insert(p1);
    mp.insert(p2);
    mp.insert(p3);

    mp["Chandan"]=25;
    cout<<mp.size()<<endl;
    for(pair<string,int> p:mp){
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<endl;

    mp.erase("Chandan");

    for(auto p:mp){
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<mp.size()<<endl;
    return 0;
}
