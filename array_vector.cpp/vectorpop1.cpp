#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    cout<<v.size()<<" ";
    cout<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    v.pop_back();
    v.pop_back();
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}