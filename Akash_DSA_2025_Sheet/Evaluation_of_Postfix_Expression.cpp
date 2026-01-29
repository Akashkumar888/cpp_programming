
int arithmetic(string &ch, int val1, int val2) {
  if (ch == "+") return val1 + val2;
  else if (ch == "-") return val1 - val2;
  else if (ch == "*") return val1 * val2;
  return val1 / val2;
}

int evaluate(vector<string>& arr) {
  stack<int> st;
  for (string &ch : arr) {
      if (ch == "+" || ch == "-" || ch == "*" || ch == "/") {
          int val1 = st.top(); st.pop();
          int val2 = st.top(); st.pop();
          int val = arithmetic(ch, val2, val1);
          st.push(val);
      } else {
          st.push(stoi(ch));
      }
  }
  return st.top();
}
