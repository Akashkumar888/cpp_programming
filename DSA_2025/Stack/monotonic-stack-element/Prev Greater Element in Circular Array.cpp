
class Solution {
public:
// Previous Greater Element (circular, backward)
    vector<int> prevGreater(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        ans[0] = -1;
        st.push(arr[0]);
        for (int i = 1; i < 2*n; i++) {
            int idx = (i-1+n) % n; // backward circular
            while (!st.empty() && st.top() <= arr[idx]) st.pop();
            ans[idx] = (st.empty() ? -1 : st.top());
            st.push(arr[idx]);
        }
        return ans;
    }
  };


class Solution{
public:
  // Previous Greater Element (circular, backward direction)
    vector<int> prevGreater(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        ans[0] = -1;
        st.push(arr[0]);
        for (int i = 1; i < 2*n; i++) {
            int idx = (i % n); // backward circular simulation
            while (!st.empty() && st.top() <= arr[idx]) st.pop();
            ans[idx] = (st.empty() ? -1 : st.top());
            st.push(arr[idx]);
        }
        return ans;
    }
  };

  