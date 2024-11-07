#include<bits/stdc++.h>
using namespace std;
int main(){
vector<int>v(10); // size increase or decrease after this 
for(int i=0;i<10;i++){
cout<<v[i]<<" ";
}
cout<<endl;
vector<int>v1(10,5);
for(int i=0;i<10;i++){
cout<<v1[i]<<" ";
}
cout<<endl;
v.push_back(4);
v.push_back(6);
v.push_back(7);
for(int i=0;i<v.size();i++){
cout<<v[i]<<" ";
}
return 0;
}