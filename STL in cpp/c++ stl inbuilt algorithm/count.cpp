#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v={2,6,3,1,6,7,6,6};
    for( auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    auto it= count(v.begin(),v.end(),6);
    cout<<(it);
    return 0;
}