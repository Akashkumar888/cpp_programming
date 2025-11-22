class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        vector<int>firstIdx(26,-1);
        vector<int>lastIdx(26,-1);
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            if(firstIdx[idx]==-1)firstIdx[idx]=i;
            else lastIdx[idx]=i;
        }
        int count=0;
        for(int i=0;i<26;i++){
            unordered_set<char>st;
            if(firstIdx[i]!=-1 && lastIdx[i]!=-1){
                for(int j=firstIdx[i]+1;j<lastIdx[i];j++){
                    //Unique Length-3 Palindromic
                    st.insert(s[j]);
                }
            }
            count+=st.size();
        }
        return count;
    }
};