#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v={1,3,5,6,7};
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl<<endl;
    vector<pair<int,int>>v1={{1,2},{2,3},{3,4}};
    vector<pair<int,int>>:: iterator it;
    for(it=v1.begin();it!=v1.end();it++){
       cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    cout<<endl;
    for(it=v1.begin();it!=v1.end();it++){
       cout<<(it->first)<<" "<<(it->second)<<endl;
    }
    return 0;
}