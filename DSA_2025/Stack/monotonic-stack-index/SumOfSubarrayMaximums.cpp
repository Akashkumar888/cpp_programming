




// Sum of maximum of all subarrays → use Previous Greater and Next Greater indices.
// How far right you can extend before finding a smaller (or greater) element → Next Smaller/Greater.




// Similarly, for maximums:
// Contribution of arr[i] =
// arr[i] * (i - prevGreaterIdx[i]) * (nextGreaterIdx[i] - i)


// Sum of subarray maximums → prevGreaterIdx + nextGreaterIdx
// SumOfSubarrayMaximums → uses prevGreaterIdx and nextGreaterIdx.



#include <bits/stdc++.h>
using namespace std;

class SumOfSubarrayMaximums {
public:
    vector<int> prevGreaterIdx(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            ans[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }
        return ans;
    }

    vector<int> nextGreaterIdx(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            ans[i] = (st.empty() ? n : st.top());
            st.push(i);
        }
        return ans;
    }

    long long sumOfSubarrayMaximums(vector<int> &arr) {
        int n = arr.size();
        vector<int> prev = prevGreaterIdx(arr);
        vector<int> next = nextGreaterIdx(arr);

        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            total += (long long)arr[i] * left * right;
        }
        return total;
    }
};



class Solution {
public:
    vector<int> pgi(int n, vector<int>& arr) { // previous greater index
        vector<int> ans(n);
        stack<int> st;
        ans[0] = -1;
        st.push(0);
        for (int i = 1; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            ans[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }
        return ans;
    }

    vector<int> ngi(int n, vector<int>& arr) { // next greater index
        vector<int> ans(n);
        stack<int> st;
        ans[n - 1] = n;
        st.push(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop(); // duplicates handled
            ans[i] = (st.empty() ? n : st.top());
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        long long totalSum = 0;
        vector<int> previous_greater_index = pgi(n, arr);
        vector<int> next_greater_index = ngi(n, arr);

        for (int i = 0; i < n; i++) {
            long long left_side_me_kaha_tak_greater_hai = i - previous_greater_index[i];
            long long right_side_me_kaha_tak_greater_hai = next_greater_index[i] - i;
            long long maxSum_subarray_count = left_side_me_kaha_tak_greater_hai * right_side_me_kaha_tak_greater_hai;
            long long sum = (1LL * arr[i] * maxSum_subarray_count) % mod;
            totalSum = (sum + totalSum) % mod;
        }
        return totalSum;
    }
};


// 👉 For each element arr[i], count how many subarrays have arr[i] as the maximum, and add its contribution.

// So the formula is: Contribution of arr[i]=arr[i]×(#of subarrays where arr[i] is max)
// On the left, you can extend until you hit a greater element (otherwise, that greater would be the max).
// On the right, you can extend until you hit a greater or equal element (to handle duplicates properly).
// So:

// prevGreater[i] = index of previous greater element (to the left).
// nextGreater[i] = index of next greater element (to the right).

// Then:
// left = i - prevGreater[i] → how many choices for the left boundary.
// right = nextGreater[i] - i → how many choices for the right boundary.

// Total subarrays where arr[i] is max: left×right
// ✅ Final Formula Contribution of arr[i]=arr[i]×(i−prevGreater[i])×(nextGreater[i]−i)
// Sum this over all i.


// 🔑 When to use left × right?
// Always when counting number of subarrays where an element is the minimum/maximum.
// Works for problems like:
// Sum of Subarray Minimums / Maximums
// Largest Rectangle in Histogram
// Product of Subarray Minimums
// ⚡ So the difference between your longest subarray problem and this sum of subarray max problem is:
// In longest subarray: you only need the length of valid subarray, so you use (nextGreater - prevGreater - 1).
// In sum of subarray maximums: you need the count of subarrays → so you multiply (i - prev) * (next - i).
