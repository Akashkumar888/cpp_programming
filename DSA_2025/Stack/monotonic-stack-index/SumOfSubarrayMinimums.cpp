



// Sum of minimum of all subarrays → use Previous Smaller and Next Smaller indices.
// How far left you can extend before finding a smaller (or greater) element → Previous Smaller/Greater.



// For sum of subarray minimums:
// Contribution of arr[i] =
// arr[i] * (i - prevSmallerIdx[i]) * (nextSmallerIdx[i] - i)

// Sum of subarray minimums → prevSmallerIdx + nextSmallerIdx
// SumOfSubarrayMinimums → uses prevSmallerIdx and nextSmallerIdx.


#include <bits/stdc++.h>
using namespace std;

class SumOfSubarrayMinimums {
public:
    vector<int> prevSmallerIdx(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            ans[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }
        return ans;
    }

    vector<int> nextSmallerIdx(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            ans[i] = (st.empty() ? n : st.top());
            st.push(i);
        }
        return ans;
    }

    long long sumOfSubarrayMinimums(vector<int> &arr) {
        int n = arr.size();
        vector<int> prev = prevSmallerIdx(arr);
        vector<int> next = nextSmallerIdx(arr);

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
vector<int>psi(int n,vector<int>&arr){
    vector<int>ans(n);
    stack<int>st;
    ans[0]=-1;
    st.push(0);
    for(int i=1;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
        ans[i]=(st.empty()?-1:st.top());
        st.push(i);
    }
    return ans;
}
vector<int>nsi(int n,vector<int>&arr){
    vector<int>ans(n);
    stack<int>st;
    ans[n-1]=n;
    st.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && arr[st.top()] > arr[i])st.pop(); // duplicate sum na ho isliye > only 
        ans[i]=(st.empty()?n:st.top());
        st.push(i);
    }
    return ans;
}
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int mod=1e9+7;
        int totalSum=0;
        vector<int>previous_smaller_index=psi(n,arr);
        vector<int>next_smaller_index=nsi(n,arr);
        for(int i=0;i<n;i++){
        long long left_side_me_kaha_tak_small_hai=i-previous_smaller_index[i];
        long long right_side_me_kaha_tak_small_hai=next_smaller_index[i]-i;
        long long minSum_subarray_count=left_side_me_kaha_tak_small_hai*right_side_me_kaha_tak_small_hai;
        long long sum=(arr[i]*minSum_subarray_count)%mod;
        totalSum=(sum+totalSum)%mod;
        }
    return totalSum;
    }
};


