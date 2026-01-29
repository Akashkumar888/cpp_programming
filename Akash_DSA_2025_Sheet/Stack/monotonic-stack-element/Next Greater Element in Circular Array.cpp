
class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        // code here
        arr.insert(arr.end(),arr.begin(),arr.end()); // duplicate
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        ans[n-1]=-1;
        st.push(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i])st.pop();
            ans[i]=(st.empty()?-1:st.top());
            st.push(arr[i]);
        }
        vector<int>result;
        for(int i=0;i<(n/2);i++){
            result.push_back(ans[i]);
        }
        return result;
    }
};


class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        ans[n-1]=-1;
        st.push(arr[n-1]);
        for(int i=2*n-2;i>=0;i--){
            int idx=(i-1+n)%n; // for moving backward direction in circular ways 
            // index in circular backward order.
            //int idx = (i+1)%n; // to go forward one step in a circular array. 
            // Pop all smaller or equal elements
            while(!st.empty() && st.top()<=arr[idx])st.pop();
            ans[idx]=(st.empty()?-1:st.top());
            st.push(arr[idx]);
        }
        return ans;
    }
};




class Solution {
public:
 vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        stack<int> st;
        for (int i=2*n-1; i >= 0; i--) {
            int idx = (i-1+n)%n; // to go backward one step in a circular array. 
            //int idx = (i+1)%n; // to go forward one step in a circular array. 
            // Pop all smaller or equal elements
            while (!st.empty() && st.top() <= nums[idx]) {
                st.pop();
            }
            // Only set answer in the first pass (i < n)
            if (i < n) {
                ans[idx]=(st.empty()?-1:st.top());
            }
            // Push current element into the stack
            st.push(nums[idx]);
        }
        return ans;
    }
};

// 👉 My advice: use Version 3 in interviews and explain Version 1 as the brute force (duplicate trick), then refine to Version 3 as optimized. This shows progression in your thought process.

// Time Complexity:
// Loop runs 2n times → O(n)
// Stack operations amortized O(n)

// Space Complexity:
// No duplication of array
// Stack → O(n)
// Answer array → O(n)
// ✅ Overall: O(n) time, O(n) space (same as Version 2, but cleaner logic).
