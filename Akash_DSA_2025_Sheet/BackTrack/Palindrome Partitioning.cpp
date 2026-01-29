
class Solution {
public:
bool isPalindrome(int i,int j,string &s){
    while(i<=j){
        if(s[i]!=s[j])return false;
        i++,j--;
    }
    return true;
}
void solve(int i,int n,string &s,vector<string>&ans,vector<vector<string>>&result){
    if(i>=n){
        result.push_back(ans);
        return;
    }
    for(int j=i;j<n;j++){
        if(isPalindrome(i,j,s)){// ek bar check kr lo valid 
            ans.push_back(s.substr(i,j-i+1));
            solve(j+1,n,s,ans,result);
            ans.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>>result;
        vector<string>ans;
        solve(0,n,s,ans,result);
        return result;
    }
};