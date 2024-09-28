
#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>&p1,pair<int,int>&p2){
    double r1=(p1.first*1.0)/(p1.second*1.0);
    double r2=(p2.first*1.0)/(p2.second*1.0);
    return r1>r2;
}

double fractionalKnapsack(vector<int>&profit,vector<int>&weight,int n,int W){
vector<pair<int,int>>arr;
for(int i=0;i<n;i++){
    arr.push_back({profit[i],weight[i]});
}
sort(arr.begin(),arr.end(),cmp);
double result=0;
for(int i=0;i<n;i++){
    if(arr[i].second<=W){
        result+=arr[i].first;
        W-=arr[i].second;
    }
    else{
        result+=((arr[i].first*1.0)/(arr[i].second*1.0))*W;
        W=0;
        break;
    }
}
return result;
}
int main(){
    vector<int>profit={5,10,15,7,8,9,4};
    vector<int>weight={1,3,5,4,1,3,2};
    int W=15;
    int n=profit.size();
cout<<"Maximun Profit: "<<fractionalKnapsack(profit,weight,n,W);
    return 0;
}