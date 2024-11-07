#include<iostream>
#include<vector>
using namespace std;
int main(){

vector<int>v;

vector<int>a(5,1);
vector<int>last (a);
cout<<"Print last"<<endl;
for(int i:last){
    cout<<i<<" ";
}
cout<<endl;
cout<<"Size ->"<<v.capacity()<<endl;

v.push_back(2);

v.push_back(7);

v.push_back(5);

v.push_back(8);

v.push_back(90);

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
cout<<"After  clear size :"<<v.size()<<endl;
    return 0;
}