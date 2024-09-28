


#include<iostream>
#include<set>
#include<map>
using namespace std;
int main(){
map<string,int>mp;
mp["raghav"]=76;
mp["harsh"]=10;
mp["sanket"]=52;
for(auto &it:mp){
    cout<<it.first<<" ";
}
cout<<endl;
for(auto &it:mp){
    cout<<it.second<<" ";
}
    return 0;
}