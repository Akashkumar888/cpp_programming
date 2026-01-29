

class Solution{
  public:
// Previous Smaller Element Index
    vector<int> prevSmallerIdx(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st; // store indices
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            ans[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }
        return ans;
    }
  };

  