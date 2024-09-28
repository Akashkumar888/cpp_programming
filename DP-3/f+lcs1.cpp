
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
vector<vector<int>>dp;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.size();
        int m = s2.size();
        dp.clear();
        dp.resize(n + 1, vector<int>(m + 1, 0));

        for(int i = n - 1; i >= 0; --i) {
            for(int j = m - 1; j >= 0; --j) {
                if(s1[i] == s2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        cout<<dp[0][0]; 
}