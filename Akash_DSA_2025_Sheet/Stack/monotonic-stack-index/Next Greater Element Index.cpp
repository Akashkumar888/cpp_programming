
class Solution {
public:
    // Next Greater Element Index
    vector<int> nextGreaterIdx(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st; // store indices
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            ans[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }
        return ans;
    }
  };
  