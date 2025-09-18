class Solution {
public:
// Next Smaller Element (circular, forward)
    vector<int> nextSmaller(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        ans[n-1] = -1;
        st.push(arr[n-1]);
        for (int i = 2*n-2; i >= 0; i--) {
            int idx = (i+1) % n; // forward circular
            while (!st.empty() && st.top() >= arr[idx]) st.pop();
            ans[idx] = (st.empty() ? -1 : st.top());
            st.push(arr[idx]);
        }
        return ans;
    }
  };

  

class Solution {
public:  
// Next Smaller Element (circular, forward direction)
    vector<int> nextSmaller(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        ans[n-1] = -1;
        st.push(arr[n-1]);
        for (int i = 2*n-2; i >= 0; i--) {
            int idx = (i + n) % n; // forward circular
            while (!st.empty() && st.top() >= arr[idx]) st.pop();
            ans[idx] = (st.empty() ? -1 : st.top());
            st.push(arr[idx]);
        }    
        return ans;
    }    
  };  




  

  





