
class Solution {
	public:
	string postToInfix(string &s) {
		// code here
		int n = s.size();
		stack<string>st;
		for (int i = 0; i < n; i++) {
			if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i]=='%' || s[i]=='^') {
				string first = st.top();
				st.pop();
				string second = st.top();
				st.pop();
				// Postfix = operand1 operand2 operator
				string temp = string(1,'(') + second  + string(1, s[i]) + first + string(1,')');
				st.push(temp);
			}
			else{
				st.push(string(1, s[i]));
			// not use to_string() for convert number to string
			// So string(1, c) means "make a string of length 1 containing character c."
			}
		}
		return st.top();
		
	}
};
