#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v={4,5,5,25,7,8};
    int n=v.size();
    sort(v.begin(),v.end());
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    auto it=lower_bound(v.begin(),v.end(),6);
    if(it==v.end()){
        cout<<"Not found";
        return 0;
    }
    cout<<*it<<endl;
    return 0;
}