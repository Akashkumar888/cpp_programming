#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v;
    cout<<"capacity: "<<" ";
     v.push_back(1);
    cout<<v.capacity()<<"->";
     v.push_back(2);
    cout<<v.capacity()<<"->";
     v.push_back(9);
    cout<<v.capacity()<<"->";
     v.push_back(68);
    cout<<v.capacity()<<" ";
    cout<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    v.pop_back();
    v.pop_back();
    cout<<v.capacity()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}