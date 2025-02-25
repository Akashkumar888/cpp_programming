
#include <bits/stdc++.h>
using namespace std;

vector<int> previous_smallest_index(int n, vector<int>& arr) {
    stack<int> st;
    vector<int> ans(n);
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

vector<int> next_smallest_index(int n, vector<int>& arr) {
    stack<int> st;
    vector<int> ans(n);
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

int getMaxArea(vector<int>& arr) {
    int n = arr.size();
    vector<int> f1 = previous_smallest_index(n, arr);
    vector<int> f2 = next_smallest_index(n, arr);
    int maxarea = 0;
    for (int i = 0; i < n; i++) {
        int width = f2[i] - f1[i] - 1;
        int height = arr[i];
        int area = width * height;
        maxarea = max(maxarea, area);
    }
    return maxarea;
}

int main() {
    vector<int> histogram = {2, 1, 5, 6, 2, 3};
    cout << "Max Area: " << getMaxArea(histogram) << endl;
    return 0;
}

