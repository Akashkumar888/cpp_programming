#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>v;
    int n;
    cin>>n;
    int t;
    for(int i=0;i<n;i++){
        cin>>t;
        v.push_back(t);
    }
    vector<int>v2(v.size());
    for(int i=0;i<v.size();i++){
        v2[i]=v[v.size()-i-1];
        cout<<v2[i]<<" ";
    }
    return 0;
}