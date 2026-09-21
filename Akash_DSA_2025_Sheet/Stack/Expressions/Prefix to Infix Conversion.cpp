
class Solution {
	public:
	string preToInfix(string &s) {
		// code here
		int n = s.size();
		stack<string>st;
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '^') {
				string first = st.top();
				st.pop();
				string second = st.top();
				st.pop();
				// Postfix = operand1 operand2 operator
				string temp = string(1, '(') + first + string(1, s[i]) + second + string(1, ')');
				st.push(temp);
			}
			else {
				st.push(string(1, s[i]));
				// not use to_string() for convert number to string
				// So string(1, c) means "make a string of length 1 containing character c."
			}
		}
		return st.top();
	}
};
