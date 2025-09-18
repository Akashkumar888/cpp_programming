
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxlen=0;
        int n=s.size();
        stack<int>st;
        st.push(-1);
        for(int i=0;i<n;i++){
            if(s[i]=='(')st.push(i);
            else{
                if(!st.empty()) st.pop();
                if(!st.empty()) {
                int len=i-st.top();
                maxlen=max(maxlen,len);
                }
                else st.push(i);
            }
        }
        return maxlen;
    }
};


