#include<bits/stdc++.h>
using namespace std;
int main(){
    map<set<int,int>,int>m;
   set<int> s1={1,2,3};
   set<int> s2={1,2,3,4};
    cout<< (s1<s2)<<endl;
    cout<< (s1>s2)<<endl;
    return 0;
}