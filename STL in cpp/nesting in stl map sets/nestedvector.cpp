#include<bits/stdc++.h>
using namespace std;
int main(){
    map<pair<string,string>,vector<int>>mpv;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        string s1,s2;
        cin>>s1>>s2;
        int count;
        cin>>count;
        for(int j=0;j<count;j++){
            int x;
            cin>>x;
            mpv[{s1,s2}].push_back(x);
        }
    }
    for(auto &pr:mpv){
        auto &fullname=pr.first;
        auto &list=pr.second;
        cout<<fullname.first<<" "<<fullname.second<<" ";
        cout<<list.size()<<endl;
        for(auto ele:list){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}