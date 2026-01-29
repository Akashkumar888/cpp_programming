
// Operator comes before operands.
// Example: + A B
// Evaluated right to left using a stack.
// No parentheses needed.

class Solution {
public:
    int arithmetic(int val1, int val2, string &op) {
        if(op=="+") return val1 + val2;
        else if(op=="-") return val1 - val2;
        else if(op=="*") return val1 * val2;
        else return val1 / val2; // integer division
    }

    int evaluatePrefix(vector<string>& arr) {
        stack<int> st;
        // iterate from right to left
        for(int i = arr.size()-1; i >= 0; i--){
            string &ch = arr[i];
            if(ch=="+" || ch=="-" || ch=="*" || ch=="/"){
                int val1 = st.top(); st.pop();
                int val2 = st.top(); st.pop();
                int val = arithmetic(val1, val2, ch);
                st.push(val);
            }
            else st.push(stoi(ch));
        }
        return st.top();
    }
};


