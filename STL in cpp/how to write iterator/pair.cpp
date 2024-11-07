#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v={1,2,3,4,5};
    vector<int>:: iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;
    vector<pair<int,int>>v1={{6,7},{5,9}};
    cout<<endl;
    for( pair<int,int>& akash:v1){
        cout<<akash.first<<" "<<akash.second<<endl;
    }
    cout<<endl;
    for( auto akash:v1){
        cout<<akash.first<<" "<<akash.second<<endl;
    }
    cout<<endl;
    return 0;
}