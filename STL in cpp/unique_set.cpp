#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v={1,2,2,3,3,4,10,3,5,6,9,1,6,8,1,2,3,4,5,6,7,8,9,0};
    set<int>st1(begin(v),end(v));
    for(auto &i:st1){
        cout<<i<<" ";
    }
    return 0;
}