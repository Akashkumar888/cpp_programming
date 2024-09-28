#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>v;
     v.push_back(1);
     v.push_back(2);
     v.push_back(9);
     v.push_back(68);
     v.at(2)=35;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    sort(v.begin(),v.end());
   cout<<endl;
   for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
  // sort(v.rbegin(),v.rend());
   reverse(v.begin(),v.end());
   cout<<endl;
   for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}