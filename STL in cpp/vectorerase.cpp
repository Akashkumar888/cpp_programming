#include<bits/stdc++.h>
using namespace std;
   int main(){
vector<int>v;
for(int i=1;i<=10;i++){
    v.push_back(i);
}
// erase 7th element
   v.erase(v.begin()+6);
// erase first three element
   v.erase(v.begin(),v.begin()+3);

   //erase from 2nd index to 4
   // v.erase(v.begin()+1,v.begin()+4);
   // sort(v.rbegin(), v.rend());
    // sort(v.begin(),v.end());
    // reverse(v.begin(), v.end());
    
   for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
   }
   // 4 5 6 8 9 10
    return 0;
}