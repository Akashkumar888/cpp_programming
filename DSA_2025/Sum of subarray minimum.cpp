

class Solution {
  public:
  //minimum elements of every possible subarrays. 
  // then smaller idx find 
  vector<int> nsi(int n,vector<int>&arr){
      vector<int>ans(n);
      stack<int>st;
      ans[n-1]=n; // next 
      st.push(n-1);
      for(int i=n-2;i>=0;i--){
          while(!st.empty() && arr[st.top()]>=arr[i])st.pop(); 
          ans[i]=(st.empty()? n :st.top());
          st.push(i);
      }
      return ans;
  }
  vector<int> psi(int n,vector<int>&arr){
      vector<int>ans(n);
      stack<int>st;
      ans[0]=-1; // previous 
      st.push(0);
      for(int i=1;i<n;i++){
          while(!st.empty() && arr[st.top()]>arr[i])st.pop();
          ans[i]=(st.empty()?-1:st.top());
          st.push(i);
      }
      return ans;
  }
    int sumSubMins(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>previous_smaller_idx=psi(n,arr);
        vector<int>next_smaller_idx=nsi(n,arr);
        int totalSum=0;
        for(int i=0;i<n;i++){
        int left_side_me_kaha_tak_small_hai=i-previous_smaller_idx[i];
        int right_side_me_kaha_tak_small_hai=next_smaller_idx[i]-i;
        int minSum_subarray_count=left_side_me_kaha_tak_small_hai*right_side_me_kaha_tak_small_hai;
        int sum=(arr[i]*minSum_subarray_count);
        totalSum=(sum+totalSum);
        }
        return totalSum;
    }
};


// ⏱ Time Complexity
// Let n = arr.size().
// Building NSI/NGI and PSI/PGI arrays:
// Each index is pushed and popped at most once to the stack.
// So, each of the 4 functions (nsi, psi, ngi, pgi) runs in O(n) time.
// Final loop to compute the total sum:
// Iterates over n elements once → O(n).
// ✅ Total Time Complexity = O(n)
// (Linear time for both minimum and maximum variants)

// 🧠 Space Complexity
// Auxiliary space for:
// previous_smaller_idx or previous_greater_idx → O(n)
// next_smaller_idx or next_greater_idx → O(n)
// stack → O(n) in the worst case
// So, total space used = O(n).
// ✅ Total Space Complexity = O(n)



class Solution {
  public:
  //maximum elements of every possible subarrays. 
  // then greater idx find 
  vector<int> ngi(int n, vector<int>& arr) {
      vector<int> ans(n);
      stack<int> st;
      ans[n - 1] = n; // next
      st.push(n - 1);
      for (int i = n - 2; i >= 0; i--) {
          while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
          ans[i] = (st.empty() ? n : st.top());
          st.push(i);
      }
      return ans;
  }

  vector<int> pgi(int n, vector<int>& arr) {
      vector<int> ans(n);
      stack<int> st;
      ans[0] = -1; // previous
      st.push(0);
      for (int i = 1; i < n; i++) {
          while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
          ans[i] = (st.empty() ? -1 : st.top());
          st.push(i);
      }
      return ans;
  }

  int sumSubMaxs(vector<int>& arr) {
      int n = arr.size();
      vector<int> previous_greater_idx = pgi(n, arr);
      vector<int> next_greater_idx = ngi(n, arr);
      int totalSum = 0;

      for (int i = 0; i < n; i++) {
          int left_side_me_kaha_tak_greater_hai = i - previous_greater_idx[i];
          int right_side_me_kaha_tak_greater_hai = next_greater_idx[i] - i;
          int maxSum_subarray_count = left_side_me_kaha_tak_greater_hai * right_side_me_kaha_tak_greater_hai;
          int sum = (arr[i] * maxSum_subarray_count);
          totalSum = (sum + totalSum);
      }

      return totalSum;
  }
};


