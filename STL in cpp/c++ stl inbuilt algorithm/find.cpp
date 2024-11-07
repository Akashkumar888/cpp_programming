#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v={2,6,3,1,6,7,6,6};
    for( auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    auto it= find(v.begin(),v.end(),10);
    if(it!=v.end()){
    cout<<(*it);
    }
    else cout<<"Not found";
    return 0;
}