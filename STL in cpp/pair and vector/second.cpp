#include<bits/stdc++.h>
using namespace std;
int main(){
 pair<int,string>p(123,"vikash");
 cout<<p.first<<" "<<p.second;
 cout<<endl;
 p=make_pair(12,"GEEKS FOR GEEKS IS BEST");
 cout<<p.first<<" "<<p.second;
 cout<<endl;
 cin>>p.first;
 cin>>p.second;
 cout<<p.first<<" "<<p.second;
return 0;
}