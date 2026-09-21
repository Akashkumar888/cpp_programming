
class Solution {
public:
    int precedence(char op) {
        if (op == '^')return 3;
        if (op == '*' || op == '/')return 2;
        if (op == '+' || op == '-')return 1;
        return 0;
    }
    string infixToPostfix(string& s) {
        string ans;
        stack<char> st;
        for (char &ch : s) {
            // Operand
            if (isalnum(ch)) {
                ans += ch;
            }
            // Opening bracket
            else if (ch == '(') {
                st.push(ch);
            }
            // Closing bracket
            else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.pop(); // remove '('
            }
            // Operator
            else {
                while (!st.empty() &&
                       st.top() != '(' &&
                       (precedence(st.top()) > precedence(ch) ||
                       (precedence(st.top()) == precedence(ch)
                        && ch != '^'))) {
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        // Remaining operators
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};