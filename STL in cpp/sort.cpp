#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v;
   int n;
   cout<<"Enter the size of  array :";
   cin>>n;
   int a;
   for(int i=0;i<n;i++){
    cin>>a;
     v.push_back(a);
   }
    sort(v.begin(),v.end());
    cout<<"sort : "<<"  ";
    for( auto x: v){
        cout<<x<<" ";
    }
    return 0;
}