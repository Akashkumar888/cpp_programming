#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
int dp[1001][1001];
string ans="";
int solve(string &s1,string &s2,int i,int j,string output){
if(output.size()>ans.size())ans=output;

    if(i>=s1.size())return 0;
    if(j>=s2.size())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i]==s2[j]){
    return dp[i][j]=1+solve(s1,s2,i+1,j+1,output+s1[i]);
    }  
    else{
     return dp[i][j]=max(solve(s1,s2,i+1,j,output),solve(s1,s2,i,j+1,output));
    }
    }
int main(){
    string s1,s2;
    cin>>s1>>s2;
    memset(dp,-1,sizeof(dp));
    solve(s1,s2,0,0,"");   
    cout<<ans;
}
