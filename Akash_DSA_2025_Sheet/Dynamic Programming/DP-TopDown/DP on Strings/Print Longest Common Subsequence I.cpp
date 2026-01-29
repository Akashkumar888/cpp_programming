
class Solution {
  public:
    void printingLCS(string &s1, string &s2) {
        // code here
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)dp[i][0]=0;
        for(int j=1;j<=m;j++)dp[0][j]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])dp[i][j]= 1+dp[i-1][j-1];
                else dp[i][j]= 0+max(dp[i-1][j],dp[i][j-1]);// ye else me rahega bottom up me 
            }
        }
        // return dp[n][m];
        int len=dp[n][m];
        string ans="";
        for(int i=0;i<len;i++){
          ans+='$';
        }
        int k=len-1;
        int i=n,j=m;
        while(i>0 && j>0){
          if(s1[i-1]==s2[j-1]){
            ans[k]=s1[i-1];
            // ans[k]=s2[j-1];
            k--;
            i--,j--;
          }
          else if(dp[i-1][j]>dp[i][j-1]){
            i--;
          }
          else if(dp[i][j-1]>=dp[i-1][j]){
            j--;
          }
    //       else {
    //     j--;   // handles dp[i-1][j] == dp[i][j-1] ALSO
    // }
        }
        cout<<ans<<endl;
    }
};



class Solution {
  public:
    void  printingLCS(string &s1, string &s2) {
        // code here
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)dp[i][0]=0;
        for(int j=1;j<=m;j++)dp[0][j]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])dp[i][j]= 1+dp[i-1][j-1];
                else dp[i][j]= 0+max(dp[i-1][j],dp[i][j-1]);// ye else me rahega bottom up me 
            }
        }
        // return dp[n][m];
        int len=dp[n][m];
        string ans(len,'$');
        int k=len-1;
        int i=n,j=m;
        while(i>0 && j>0){
          if(s1[i-1]==s2[j-1]){
            ans[k]=s1[i-1];
            // ans[k]=s2[j-1];
            k--;
            i--,j--;
          }
          else if(dp[i-1][j]>dp[i][j-1]){
            i--;
          }
          else if(dp[i][j-1]>=dp[i-1][j]){
            j--;
          }
    //       else {
    //     j--;   // handles dp[i-1][j] == dp[i][j-1] ALSO
    // }
        }
        cout<<ans<<endl;
    }
};

class Solution {
public:
    void printingLCS(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        int len = dp[n][m];
        string ans(len, '$');

        int i = n, j = m, k = len - 1;
        while(i > 0 && j > 0){
            if(s1[i-1] == s2[j-1]){
                ans[k--] = s1[i-1];
                i--; j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }

        cout << ans << endl;
    }
};

