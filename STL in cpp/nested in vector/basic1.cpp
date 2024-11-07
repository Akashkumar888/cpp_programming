#include<bits/stdc++.h>
using namespace std;
 void printVec(vector<pair<int,int>>&v){
    cout<<"size: "<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    cout<<endl;
}
int main(){
vector<pair<int,int>>v;
int n;
cin>>n;
int x,y;
for(int i=0;i<n;i++){
    cin>>x>>y;
    // v.push_back({x,y});
    v.push_back(make_pair(x,y));
}
printVec(v);
    return 0;
}