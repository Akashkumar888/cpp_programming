#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v1={1,14,26,38,60};
    vector<int>v2={20,30,55,45,89};
    vector<int>v3;
    cout<<v1.size()<<endl;
    cout<<v2.size()<<endl;
    int a=v1.size();
    int b=v2.size();
    for(int i=0;i<a;i++){
        v3.push_back (v1[i]);
    }
    for(int i=0;i<b;i++){
        v3.push_back (v2[i]);
    }

    cout<<endl;
    sort(v3.begin(),v3.end());
    for(auto  i:v3){
        cout<<i<<"  ";
    }
    cout<<endl;
    return 0;
}