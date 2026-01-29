
bool check(vector<char>&ans,char op){
    int n=ans.size();
    if(op=='!' )return ans[0]=='t'? false:true;
    else if(op=='&'){
        for(int i=0;i<n;i++){
            if(ans[i]=='f')return false;
        }
        return true;
    }
    else if(op=='|'){
        for(int i=0;i<n;i++){
            if(ans[i]=='t')return true;
        }
        return false;
    }
   return false;
}

class Solution {
public:
    bool parseBoolExpr(string s) {
        stack<char>st;
        for(char &ch:s){
         if(ch==')'){
            vector<char>ans;
         while(!st.empty() && st.top()!='('){
            ans.push_back(st.top());
            st.pop();
         }
         st.pop();

         char op=st.top();
         st.pop();

          bool flag=check(ans,op);
          st.push(flag ? 't' : 'f');
         }
         else if(ch==',')continue;
         else st.push(ch);
        }
        return st.top()=='t';
    }
};



class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char c : expression) {
            if (c == ',' || c == '(') continue;

            if (c == 't' || c == 'f' || c == '!' || c == '&' || c == '|') {
                st.push(c);
            }
            else if (c == ')') {
                bool hasTrue = false, hasFalse = false;

                while (st.top() != '!' && st.top() != '&' && st.top() != '|') {
                    if (st.top() == 't') hasTrue = true;
                    if (st.top() == 'f') hasFalse = true;
                    st.pop();
                }

                char op = st.top();
                st.pop();

                bool result;
                if (op == '!') {
                    result = !hasTrue;
                } else if (op == '&') {
                    result = !hasFalse;
                } else { // '|'
                    result = hasTrue;
                }

                st.push(result ? 't' : 'f');
            }
        }

        return st.top() == 't';
    }
};
