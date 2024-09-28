

#include<iostream>
#include<set>
#include<map>
using namespace std;
int main(){
map<int,int>mp;
mp[2]=20;
mp[3]=10;
mp[1]=30;
for(auto &it:mp){
    cout<<it.first<<" ";
}
cout<<endl;
for(auto &it:mp){
    cout<<it.second<<" ";
}
    return 0;
}