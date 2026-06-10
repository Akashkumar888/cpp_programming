
class Solution {
  public:
  // Lexicographically smallest after removing k
    string lexicographicallySmallest(string &s, int k) {
        // code here
        int n=s.size();
        int powerOfTwo = n&(n-1);
        if(n>0 && powerOfTwo==0)k=k/2;
        else k=k*2;
        if(k>=n)return "-1";
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<n;i++){
            while(!st.empty() && st.top()>s[i] && k>0){
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        // remove remaining characters
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        string result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        if(result.empty())return "-1";
        return result;
    }
};



class Solution {
  public:
  // Lexicographically smallest after removing k
    string lexicographicallySmallest(string &s, int k) {
        // code here
        int n=s.size();
        int powerOfTwo = n&(n-1);
        if(n>0 && powerOfTwo==0)k=k/2;
        else k=k*2;
        if(k>=n)return "-1";
        string result;
        result.push_back(s[0]);
        for(int i=1;i<n;i++){
            while(!result.empty() && result.back()>s[i] && k>0){
                result.pop_back();
                k--;
            }
            result.push_back(s[i]);
        }
        // remove remaining characters
        while(!result.empty() && k>0){
            result.pop_back();
            k--;
        }
        if(result.empty())return "-1";
        return result;
    }
};


class Solution {
  public:
  // Lexicographically smallest after removing k
    string lexicographicallySmallest(string &s, int k) {
        // code here
        int n=s.size();
        int powerOfTwo = n&(n-1);
        if(powerOfTwo==0)k=k/2;
        else k=k*2;
        if(k>=n)return "-1";
        string result="";
        result.push_back(s[0]);
        for(int i=1;i<n;i++){
            while(!result.empty() && result.back()>s[i] && k>0){
                result.pop_back();
                k--;
            }
            result.push_back(s[i]);
        }
        // remove remaining characters
        while(!result.empty() && k>0){
            result.pop_back();
            k--;
        }
        if(result.empty())return "-1";
        return result;
    }
};

