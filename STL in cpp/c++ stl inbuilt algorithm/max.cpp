#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v={2,3,1,6,7,6};
    for( auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    auto it= max_element(v.begin(),v.end());
    cout<<(*it);
    return 0;
}