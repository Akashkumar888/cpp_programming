
vector<int> nextLargerElement(vector<int>& arr) {
  int n = arr.size();
  vector<int> ans(n);
  stack<int> st;  

  ans[n - 1] = -1;  // Rightmost element has no next greater element
  st.push(arr[n - 1]);

  for (int i = n - 2; i >= 0; i--) {
      while (!st.empty() && st.top() <= arr[i]) {
          st.pop();  // Remove smaller elements
      }
      ans[i] = st.empty() ? -1 : st.top();  // Assign next greater element
      st.push(arr[i]);  // Push current element to stack
  }

  return ans;
}
