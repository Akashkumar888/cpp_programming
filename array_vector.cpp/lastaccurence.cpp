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
     v.push_back(97);
     v.push_back(2);
     v.push_back(9);
     int idx=-1;
     int x=9;
    for(int i=0;i<v.size();i++){
       if(v[i]==x) idx=i;
    }
   cout<<idx;
   
    return 0;
}