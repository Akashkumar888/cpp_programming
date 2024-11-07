#include<bits/stdc++.h>
using namespace std;
bool ispositive(int x){
    return x>0;
}
int main(){
   vector<int>v={1,2,3,4,5};
   cout<<all_of(v.begin(),v.end(),ispositive);
return 0;
}