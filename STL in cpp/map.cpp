#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,string>m;
    m[1]="Akash";
    m[0]="Vikash";
    m[8]="prakash";
    m[6]="shubham";
    m[2]="Vinay";
    m.insert({5,"College"});
    cout<<"Before erase"<<endl;
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;
    cout<<"5 is present or not :"<<m.count(5)<<endl;
    m.erase(2);
    cout<<"After erase"<<endl;
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;
    auto it=m.find(6);
    for(auto i=it;i!=m.end();i++){
        cout<<(*i).first<<" "<<(*i).second<<endl;
    }
    cout<<endl;
    return 0;
}