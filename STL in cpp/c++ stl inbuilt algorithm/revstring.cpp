#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<string>v={"akash","kumar","nitish","ankit"};
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