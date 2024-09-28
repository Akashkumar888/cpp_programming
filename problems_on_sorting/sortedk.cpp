#include<bits/stdc++.h>
using namespace std;
int main(){
vector<int>v={5,3,4,2};
int n=v.size();
sort(v.rbegin(),v.rend());
int max=INT_MIN;
for(int i=0;i<n;i++){
if(max<v[i]){
max=v[i];
}
}
for(int i=0;i<n;i++){
    cout<<abs(v[i]-max)<<" ";
}
    return 0;
}