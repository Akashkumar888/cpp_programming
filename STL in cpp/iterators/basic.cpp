#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v={1,3,5,6,7};
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    vector<int>:: iterator it=v.begin();
    cout<<(*it)<<endl;
    cout<<(*it+1)<<endl;
    cout<<(*it)+1<<endl;
    cout<<*(it+1)<<endl;
    cout<<*(it+2)<<endl;
    cout<<*(it+3)<<endl;
    cout<<*(it+4)<<endl;
    return 0;
}