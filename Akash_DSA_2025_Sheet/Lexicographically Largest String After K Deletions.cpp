
class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        int n=s.size();
        stack<char>st;
        int count=0;
        for(char &ch:s){
            while(!st.empty() && st.top()<ch && count<k){
                st.pop();
                count++;
            }
            st.push(ch);
        }
        while(!st.empty() && count<k){
            st.pop();
            count++;
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// a string can act like a stack since we can push_back and pop_back characters easily.




class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        int n=s.size();
        string ans;
        int count=0;
        for(char &ch:s){
            while(!ans.empty() && ans.back()<ch && count<k){
                ans.pop_back();
                count++;
            }
            ans.push_back(ch);
        }
        while(!ans.empty() && count<k){
            ans.pop_back();
            count++;
        }
        return ans;
    }
};


