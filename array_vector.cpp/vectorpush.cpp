#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v;
    // cout<<"size:"<<" ";
    //v.push_back(3);
    // cout<<v.size()<<" ";
    // v.push_back(4);
    // cout<<v.size()<<" ";
    // v.push_back(5);
    // cout<<v.size()<<" ";
    // v.push_back(6);
    // cout<<v.size()<<" ";
    cout<<"capacity: "<<" ";
     v.push_back(1);
    cout<<v.capacity()<<"->";
     v.push_back(2);
    cout<<v.capacity()<<"->";
     v.push_back(9);
    cout<<v.capacity()<<"->";
     v.push_back(68);
    cout<<v.capacity()<<" ";
    return 0;
}