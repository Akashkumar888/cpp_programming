#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v={2,6,3,1,6,7,6};
    for( auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    reverse(v.begin(),v.end());
    for(auto i:v){
        cout<<i<<" ";
    }
    return 0;
}