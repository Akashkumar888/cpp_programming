
class Solution {
  public:
  vector<int>nge(int n,vector<int>&arr){
      vector<int>ans(n);
      ans[n-1]=-1;
      stack<int>st;
      st.push(arr[n-1]);
      for(int i=n-2;i>=0;i--){
          while(!st.empty() && st.top()<=arr[i])st.pop();
          ans[i]=(st.empty()?-1:st.top());
          st.push(arr[i]);
      }
      return ans;
      
  }
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        int n=arr.size();
        arr.insert(arr.end(),arr.begin(),arr.end());
        vector<int>result=nge(2*n,arr);
        result.resize(n);
        return result;
    }
};

// Time Complexity:
// arr.insert(...): O(n)
// nge(2n, arr):
// Single pass of 2n elements.
// Each element is pushed and popped from the stack once → O(2n)
// result.resize(n): O(1)
// ➡️ Total Time Complexity:
// O(n) for insert + O(2n) for processing = O(n)

// Space Complexity:
// arr becomes size 2n → O(2n)
// stack → O(n) in worst case
// ans/result → O(n)
// ➡️ Total Space Complexity:
// O(n) (You create extra copies but only store 2n + n + stack)



class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int>ans(n);
        stack<int> st;
        for (int i=2*n-1; i >= 0; i--) {
            int idx = (i-1+n)%n; // to go backward one step in a circular array. 
            //int idx = (i+1)%n; // to go forward one step in a circular array. 
            // Pop all smaller or equal elements
            while (!st.empty() && st.top() <= arr[idx]) {
                st.pop();
            }
            // Only set answer in the first pass (i < n)
            if (i < n) {
                ans[idx]=(st.empty()?-1:st.top());
            }
            // Push current element into the stack
            st.push(arr[idx]);
        }
        return ans;
    }
};

// Time Complexity:
// The loop runs for 2n iterations.
// Stack operations (each element is pushed and popped at most once) → O(2n)
// ➡️ Total Time Complexity:
// O(n)

// Space Complexity:
// Stack → O(n)
// ans → O(n)
// ➡️ Total Space Complexity:
// O(n)

