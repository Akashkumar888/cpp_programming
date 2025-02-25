
#include <bits/stdc++.h>
using namespace std;

vector<int> calculateSpan(vector<int>& arr) {
    int n = arr.size();
    stack<pair<int, int>> st;
    st.push({arr[0], 1});
    vector<int> ans(n);
    ans[0] = 1;

    for (int i = 1; i < n; i++) {
        int span = 1;
        while (!st.empty() && st.top().first <= arr[i]) {
            span += st.top().second;
            st.pop();
        }
        ans[i] = span;
        st.push({arr[i], span});
    }
    return ans;
}

int main() {
    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    vector<int> result = calculateSpan(arr);
    
    for (int span : result) {
        cout << span << " ";
    }
    return 0;
}

