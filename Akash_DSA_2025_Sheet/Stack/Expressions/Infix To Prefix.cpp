
class Solution {
public:

    int precedence(char op) {
        if (op == '^')
            return 3;

        if (op == '*' || op == '/')
            return 2;

        if (op == '+' || op == '-')
            return 1;

        return 0;
    }

    string infixToPrefix(string s) {

        // Step 1: Reverse
        reverse(s.begin(), s.end());

        // Step 2: Swap parentheses
        for (char &ch : s) {

            if (ch == '(')
                ch = ')';

            else if (ch == ')')
                ch = '(';
        }

        // Step 3: Convert reversed expression to postfix
        string postfix;
        stack<char> st;

        for (char ch : s) {

            // Operand
            if (isalnum(ch)) {
                postfix += ch;
            }

            // Opening parenthesis
            else if (ch == '(') {
                st.push(ch);
            }

            // Closing parenthesis
            else if (ch == ')') {

                while (!st.empty() && st.top() != '(') {
                    postfix += st.top();
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
                        && ch == '^'))) {

                    postfix += st.top();
                    st.pop();
                }

                st.push(ch);
            }
        }

        // Step 4: Pop remaining operators
        while (!st.empty()) {
            postfix += st.top();
            st.pop();
        }

        // Step 5: Reverse postfix → prefix
        reverse(postfix.begin(), postfix.end());

        return postfix;
    }
};