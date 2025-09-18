
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

