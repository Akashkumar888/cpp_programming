#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v={1,3,5,6,7};
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    vector<int>:: iterator it=v.begin();
    cout<<endl;
    for(it=v.begin();it!=v.end();it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;
    return 0;
}