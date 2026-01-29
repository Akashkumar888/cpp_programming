
class Solution{
public:
vector<int> next_greater_index(int n, vector<int>& arr) {
    vector<int> ans(n);
    ans[n-1] = n;
    stack<int> st;
    st.push(n-1);
    for (int i = n-2; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
        ans[i] = (st.empty() ? n : st.top());
        st.push(i);
    }
    return ans;
}

vector<int> prev_greater_index(int n, vector<int>& arr) {
    vector<int> ans(n);
    ans[0] = -1;
    stack<int> st;
    st.push(0);
    for (int i = 1; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) st.pop(); // not use = for avoid duplicates
        ans[i] = (st.empty() ? -1 : st.top());
        st.push(i);
    }
    return ans;
}
vector<int> minOfMax(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, INT_MAX);
   // The result vector is 0-indexed but window sizes go from 1 to n.
// result[k] is meant to store the maximum of minimums for window size k+1.
// So if the window length is len, we should place arr[i] at result[len-1].
    vector<int> ngi = next_greater_index(n, arr);
    vector<int> pgi = prev_greater_index(n, arr);

    for (int i = 0; i < n; i++) {
        int len = ngi[i] - pgi[i] - 1;
        result[len-1] = min(result[len-1], arr[i]); 
    }

    // Fill missing values (like in maxOfMin but reversed logic)
    for (int i = n-2; i >= 0; i--) {
        result[i] = min(result[i], result[i+1]);
    }
   // Some window sizes may not get directly updated.
// Example: maybe no element is the minimum for window size 2, but there is one for size 3.
// But logically:
// Max of Min for window size 2≥Max of Min for window size 3
// Because smaller windows always have a chance to pick a larger minimum.
    return result;
}
};