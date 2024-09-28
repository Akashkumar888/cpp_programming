
#include<iostream>
using namespace std;
#include<vector>
int ans;
vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};
void f(vector<vector<int>>&nums,int i,int j,int n){
if(i<0||j<0||i>=n||j>=n||nums[i][j]==1)return ;
if(i==n-1&&j==n-1) {
    ans++;
    return;
}
int temp=nums[i][j];
nums[i][j]=1;
for(auto &dir:directions){
    int new_i=i+dir[0];
    int new_j=j+dir[1];
    f(nums,new_i,new_j,n);
}
nums[i][j]=temp;
}
int ratinmaze(vector<vector<int>>&nums,int n){
    ans=0;
    f(nums,0,0,n);
    return ans;
}
int main()
{
vector<vector<int>>nums{
{0,0,1,0,0,1,0},
{1,0,1,1,0,0,0},
{0,0,0,0,1,0,1},
{1,0,1,0,0,0,0},
{1,0,1,1,0,1,0},
{1,0,0,0,0,1,0},
{1,1,1,1,0,0,0}
};
cout<<ratinmaze(nums,7);
return 0;
}