
class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        //Expression may contain + , - , *, and / operators. 
        // () isme koi operators nhi hai to redundant bracket hai. //(b) 
        stack<char>st;
        for(char &ch:s){
            if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/')st.push(ch);
            else if(ch==')'){
                int opr=0;
                while(!st.empty() && st.top()!='('){
                    opr++;
                    st.pop();
                }
                if(opr==0)return true;
                st.pop();
            }
            else continue;
        }
        return false;
    }
};


class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        //Expression may contain + , - , *, and / operators. 
        // () isme koi operators nhi hai to redundant bracket hai. //(b) 
        stack<char>st;
        for(char &ch:s){
            if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/')st.push(ch);
            else if(ch==')'){
                bool opr=false;
                while(!st.empty() && st.top()!='('){
                    opr=true;
                    st.pop();
                }
                if(!opr)return true;
                st.pop();
            }
            else continue;
        }
        return false;
    }
};


class Solution {
  public:
    bool checkRedundancy(string &s) {
        stack<char> st;

        for(char ch : s) {
            if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
                st.push(ch);
            else if(ch == ')') {
                bool hasOp = false;

                while(!st.empty() && st.top() != '(') {
                    char t = st.top();
                    st.pop();
                    if(t=='+' || t=='-' || t=='*' || t=='/')
                        hasOp = true;
                }

                st.pop(); // remove '('

                if(!hasOp) return true; // redundant bracket
            }
        }
        return false;
    }
};
