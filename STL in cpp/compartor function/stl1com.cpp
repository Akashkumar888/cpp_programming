#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>a ,pair<int,int>b){
    if(a.first!=b.first) {
        if(a.first>b.first) return false;
        return true;
    }
    else{
        if(a.second<b.second) return false;
        return true;
    }
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end(),cmp);

    for(int i=0;i<n;i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    return 0;
}