
#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;
ll minCost(vector<ll > &x,vector<ll> &y,int m,int n){
sort(x.begin(),x.end(),greater<int>());
sort(y.begin(),y.end(),greater<int>());
int hz=1,vr=1;
int h=0,v=0;
ll ans=0;
while(h<y.size() && v<x.size()){
if(x[v]>y[h]){
    ans+=x[v]*vr;
    hz++;
    v++;
}
else{
    ans+=y[h]*hz;
    vr++;
    h++;
}
}
while(h<y.size()){
    ans+=y[h]*hz;
    vr++;
    h++;
}
while(v<x.size()){
   ans+=x[v]*vr;
    hz++;
    v++;
}
return ans;
}
int main(){
vector<ll>x={2,1,3,1,4};
vector<ll>y={4,1,2};
int m=6;
int n=4;
cout<<minCost(x,y,m,n);
    return 0;
}