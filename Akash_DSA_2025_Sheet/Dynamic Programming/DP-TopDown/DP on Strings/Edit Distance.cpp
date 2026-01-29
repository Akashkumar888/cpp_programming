
class Solution {
public:
// return the minimum number of operations required to convert word1 to word2.
// word1-> i
// word2-> j
int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp){
    if(i<0)return j+1;//j is index and number of char needed
    if(j<0)return i+1;//i is index and number of char needed
    int minStep=INT_MAX;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j])return dp[i][j]= 0+solve(i-1,j-1,s,t,dp);
    else{
        // insert hypothetical insert in word1 Insert a character
        int insertChar=1 + solve(i,j-1,s,t,dp);
        // delete hypothetical delete in word1 Delete a character
        int deleteChar=1+solve(i-1,j,s,t,dp);
        // replace hypothetical replace in word1 Replace a character
        int replaceChar=1+solve(i-1,j-1,s,t,dp);
        minStep=min({insertChar,deleteChar,replaceChar});
    }
    return dp[i][j]=minStep;
}
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        return solve(n-1,m-1,word1,word2,dp);
    }
};

class Solution {
public:
// return the minimum number of operations required to convert word1 to word2.
// word1-> i
// word2-> j
int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp){
    if(i==0)return j;//shift index j is index and number of char needed
    if(j==0)return i;//shift index i is index and number of char needed
    int minStep=INT_MAX;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i-1]==t[j-1])return dp[i][j] = 0+solve(i-1,j-1,s,t,dp);
    else{
        // insert hypothetical insert in word1 Insert a character
        int insertChar=1 + solve(i,j-1,s,t,dp);
        // delete hypothetical delete in word1 Delete a character
        int deleteChar=1+solve(i-1,j,s,t,dp);
        // replace hypothetical replace in word1 Replace a character
        int replaceChar=1+solve(i-1,j-1,s,t,dp);
        minStep=min({insertChar,deleteChar,replaceChar});
    }
    return dp[i][j]=minStep;
}
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,word1,word2,dp);
    }
};


class Solution {
public:
// return the minimum number of operations required to convert word1 to word2.
// word1-> i
// word2-> j
int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp){
    if(i<0)return j+1;//j is index and number of char needed
    if(j<0)return i+1;//i is index and number of char needed
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j])return dp[i][j]= 0+solve(i-1,j-1,s,t,dp);
        // niche ka else me rahega.
        // insert hypothetical insert in word1 Insert a character
        int insertChar=1 + solve(i,j-1,s,t,dp);
        // delete hypothetical delete in word1 Delete a character
        int deleteChar=1+solve(i-1,j,s,t,dp);
        // replace hypothetical replace in word1 Replace a character
        int replaceChar=1+solve(i-1,j-1,s,t,dp);
    return dp[i][j]=min({insertChar,deleteChar,replaceChar});
}
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        return solve(n-1,m-1,word1,word2,dp);
    }
};


class Solution {
public:
// return the minimum number of operations required to convert word1 to word2.
// word1-> i
// word2-> j
int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp){
    if(i==0)return j;//shift index j is index and number of char needed
    if(j==0)return i;//shift index i is index and number of char needed
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i-1]==t[j-1])return dp[i][j] = 0+solve(i-1,j-1,s,t,dp);
        // niche ka else me rahega.
        // insert hypothetical insert in word1 Insert a character
        int insertChar=1 + solve(i,j-1,s,t,dp);
        // delete hypothetical delete in word1 Delete a character
        int deleteChar=1+solve(i-1,j,s,t,dp);
        // replace hypothetical replace in word1 Replace a character
        int replaceChar=1+solve(i-1,j-1,s,t,dp);
    return dp[i][j]=min({insertChar,deleteChar,replaceChar});
}
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,word1,word2,dp);
    }
};

class Solution {
public:
// return the minimum number of operations required to convert word1 to word2.
// word1-> i
// word2-> j
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<=m;j++)dp[0][j]=j;// for column
        for(int i=0;i<=n;i++)dp[i][0]=i;// for row 
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1])dp[i][j] = dp[i-1][j-1];   // ✅ FIX
                else{
                    // insert hypothetical insert in word1 Insert a character
                    int insertChar=1 + dp[i][j-1];
                    // delete hypothetical delete in word1 Delete a character
                    int deleteChar=1+ dp[i-1][j];
                    // replace hypothetical replace in word1 Replace a character
                    int replaceChar=1+ dp[i-1][j-1];
                    dp[i][j] = min({insertChar, deleteChar, replaceChar});
                }
            }
        }
        return dp[n][m];
    }
};

class Solution {
public:
// return the minimum number of operations required to convert word1 to word2.
// word1-> i
// word2-> j
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int>prev(m+1,0),temp(m+1,0);
        for(int j=0;j<=m;j++)prev[j]=j;// i just required prev row 
        // for(int i=0;i<=n;i++)dp[i][0]=i;
        for(int i=1;i<=n;i++){
            temp[0]=i;// first column 
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1])temp[j] = prev[j-1];   // ✅ FIX
                else{
                    // insert hypothetical insert in word1 Insert a character
                    int insertChar=1 + temp[j-1];
                    // delete hypothetical delete in word1 Delete a character
                    int deleteChar=1+ prev[j];
                    // replace hypothetical replace in word1 Replace a character
                    int replaceChar=1+ prev[j-1];
                    temp[j] = min({insertChar, deleteChar, replaceChar});
                }
            }
            prev=temp;
        }
        return prev[m];
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> prev(m+1, 0);

        // base case: i = 0
        for(int j = 0; j <= m; j++)
            prev[j] = j;

        for(int i = 1; i <= n; i++){
            int diag = prev[0];   // dp[i-1][0]
            prev[0] = i;          // dp[i][0]

            for(int j = 1; j <= m; j++){
                int temp = prev[j];   // save dp[i-1][j]

                if(word1[i-1] == word2[j-1]){
                    prev[j] = diag;
                }
                else{
                    int insertChar  = 1 + prev[j-1]; // dp[i][j-1]
                    int deleteChar  = 1 + prev[j];   // dp[i-1][j]
                    int replaceChar = 1 + diag;      // dp[i-1][j-1]
                    prev[j] = min({insertChar, deleteChar, replaceChar});
                }

                diag = temp;  // move diagonal
            }
        }
        return prev[m];
    }
};
