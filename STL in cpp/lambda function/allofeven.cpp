#include<bits/stdc++.h>
using namespace std;
int main(){
   vector<int>v={2,4,6,8,10};
   cout<<all_of(v.begin(),v.end(),[](int x){return x%2==0;});
return 0;
}