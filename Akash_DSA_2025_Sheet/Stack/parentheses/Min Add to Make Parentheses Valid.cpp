
class Solution {
  public:
    int minParentheses(string& s) {
        // code here
         int n=s.size();
         stack<char>st;
         for(char &ch:s){
             if(!st.empty() && st.top()=='(' && ch==')')st.pop();
             else st.push(ch);
         }
         int count=0;
         while(!st.empty()){
             count++;
             st.pop();
         }
         return count;
    }
};

// ✅ Final Answer:
// Time Complexity → O(n)
// Space Complexity → O(n)


class Solution {
  public:
    int minParentheses(string& s) {
        // code here
         int n=s.size();
         int open=0,close=0;
         // Pass 1: Left to right
         for(int i=0;i<n;i++){
             if(s[i]=='(')open++;   // count extra '('
             else if(s[i]==')' && open>0)open--; // match with an open '('
         }
         // Pass 2: Right to left
         for(int i=n-1;i>=0;i--){
             if(s[i]==')')close++; // count extra ')'
             else if(s[i]=='(' && close>0)close--; // match with a close ')'
         }
         return open+close;
    }
};


class Solution {
public:
    int minAddToMakeValid(string s) {
       int open=0,close=0;
       int n=s.size();
       for(int i=0;i<n;i++){
        if(s[i]=='('){
            open++;
        }
        else if(open>0 && s[i]==')'){
            open--;
        }
        else{
            close++;
        }
       } 
       return close+open;
    }
};

