
vector<int> previous_smaller_index(int n, vector<int>& arr) {
  vector<int> ans(n);
  stack<int> st;
  ans[0] = -1;
  st.push(0);
  for (int i = 1; i < n; i++) {
      while (!st.empty() && arr[st.top()] >= arr[i]) {
          st.pop();
      }
      ans[i] = (st.empty() ? -1 : st.top());
      st.push(i);
  }
  return ans;
}

vector<int> next_smaller_index(int n, vector<int>& arr) {
  vector<int> ans(n);
  stack<int> st;
  ans[n - 1] = n;
  st.push(n - 1);
  for (int i = n - 2; i >= 0; i--) {
      while (!st.empty() && arr[st.top()] >= arr[i]) {
          st.pop();
      }
      ans[i] = (st.empty() ? n : st.top());
      st.push(i);
  }
  return ans;
}

vector<int> maxOfMins(vector<int>& arr) {
  int n = arr.size();
  vector<int> ans(n, 0);
  vector<int> next = next_smaller_index(n, arr);
  vector<int> prev = previous_smaller_index(n, arr);

  for (int i = 0; i < n; i++) {
      int k = next[i] - prev[i] - 1;
      if (k - 1 >= 0 && k - 1 < n) {
          ans[k - 1] = max(ans[k - 1], arr[i]);
      }
  }

  for (int i = n - 2; i >= 0; i--) {
      ans[i] = max(ans[i], ans[i + 1]);
  }

  return ans;
}
