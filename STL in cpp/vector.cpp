#include<iostream>
#include<vector>
using namespace std;
int main(){

vector<int>v;

cout<<"Size ->"<<v.capacity()<<endl;

v.push_back(2);
cout<<"Size ->"<<v.capacity()<<endl;

v.push_back(7);
cout<<"Size ->"<<v.capacity()<<endl;

v.push_back(5);
cout<<"Size ->"<<v.capacity()<<endl;

v.push_back(8);
cout<<"Size ->"<<v.capacity()<<endl;

v.push_back(90);
cout<<"Size ->"<<v.capacity()<<endl;

cout<<"capacity->"<<v.capacity()<<endl;
cout<<"Size ->"<<v.capacity()<<endl;

cout<<"first :"<<v.front()<<endl;
cout<<"Second :"<<v.back()<<endl;

cout<<"Before pop"<<endl;
for(int i:v){
    cout<<i<<" ";
}
cout<<endl;
v.pop_back();
for(int i:v){
    cout<<i<<" ";
}
cout<<endl;
cout<<"Before clear size :"<<v.size()<<endl;
v.clear();
cout<<"After clear size :"<<v.size()<<endl;
    return 0;
}