#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  // flow flower flight
 vector<string>v;
 v.push_back("flight");
 v.push_back("flower");
 v.push_back("flow");
 sort(v.begin(),v.end());
 for(int i=0;i<v.size();i++){
    cout<<v[i]<<" "<<endl;
 }
    return 0;
}