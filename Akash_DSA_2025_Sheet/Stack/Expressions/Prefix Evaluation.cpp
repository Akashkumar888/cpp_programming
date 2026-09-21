
class Solution {
	public:
	int arithmetic(string &ch,int val1,int val2){
     if(ch=="+")return val1+val2;
     else if(ch=="-")return val1-val2;
     else if(ch=="*")return val1*val2;
     else if (ch == "/") {
                 int q = val1 / val2;
                 int r = val1 % val2;
                 // Problem uses floor division
                 if (r != 0 && ((val1 < 0) != (val2 < 0)))q--;
                 return q;
             }
             else if (ch == "%") return val1 % val2;
             else if (ch == "^") return pow(val1, val2);
             return 0;
 }
	int evaluatePrefix(vector<string>& arr) {
		// code here
		int n = arr.size();
		stack<int>st;
		for (int i = n - 1; i >= 0; i--) {
			if (arr[i] == "+" || arr[i] == "-" || arr[i] == "*" || arr[i] == "/" || arr[i] == "%" || arr[i] == "^") {
				int first = st.top();
				st.pop();
				int second = st.top();
				st.pop();
				// Postfix = operand1 operand2 operator
				int temp = arithmetic(arr[i],first,second);
				st.push(temp);
			}
			else {
				st.push(stoi(arr[i]));
				// not use to_string() for convert number to string
				// So string(1, c) means "make a string of length 1 containing character c."
			}
		}
		return st.top();
	}
};
