
class Solution {
  public:
  vector<int>previousSmallerIndex(int n,vector<int>&arr){
      vector<int>result(n);
      stack<int>st;
      st.push(0);
      result[0]=-1;
      for(int i=1;i<n;i++){
          while(!st.empty() && arr[st.top()]>arr[i])st.pop();// to remove redundancy
          result[i]=(st.empty()?-1:st.top());
          st.push(i);
      }
      return result;
  }
  vector<int>nextSmallerIndex(int n,vector<int>&arr){
      vector<int>result(n);
      stack<int>st;
      st.push(n-1);
      result[n-1]=n;
      for(int i=n-2;i>=0;i--){
          while(!st.empty() && arr[st.top()]>=arr[i])st.pop(); 
          result[i]=(st.empty()?n:st.top());
          st.push(i);
      }
      return result;
  }
  vector<int>previousGreaterIndex(int n,vector<int>&arr){
      vector<int>result(n);
      stack<int>st;
      st.push(0);
      result[0]=-1;
      for(int i=1;i<n;i++){
          while(!st.empty() && arr[st.top()]<arr[i])st.pop();// to remove redundancy
          result[i]=(st.empty()?-1:st.top());
          st.push(i);
      }
      return result;
  }
  vector<int>nextGreaterIndex(int n,vector<int>&arr){
      vector<int>result(n);
      stack<int>st;
      st.push(n-1);
      result[n-1]=n;
      for(int i=n-2;i>=0;i--){
          while(!st.empty() && arr[st.top()]<=arr[i])st.pop();
          result[i]=(st.empty()?n:st.top());
          st.push(i);
      }
      return result;
  }
    int subarrayRanges(vector<int>& arr) {
        // code here
        int n=arr.size();
        long long totalSum=0;
        vector<int>psi=previousSmallerIndex(n,arr);
        vector<int>nsi=nextSmallerIndex(n,arr);
        vector<int>pgi=previousGreaterIndex(n,arr);
        vector<int>ngi=nextGreaterIndex(n,arr);
        for(int i=0;i<n;i++){
            long long left1=i-psi[i];
            long long right1=nsi[i]-i;
            long long minElement=(left1*right1)*arr[i];
            
            long long left2=i-pgi[i];
            long long right2=ngi[i]-i;
            long long maxElement=(left2*right2)*arr[i];
            
            totalSum+=(maxElement-minElement);
        }
        return totalSum;
    }
};

// Now your implementation is perfectly aligned with the standard and correct approach for
// “Sum of Subarray Ranges”.
// You have fixed all three critical aspects:
// Monotonic stack logic – correct for all four helpers
// Duplicate handling – using strict on one side and non-strict on the other
// Overflow safety – using long long for contributions and total sum
// Your comparisons are now exactly what they should be:
// Role	Left Side	Right Side
// Minimum	> (previous)	>= (next)
// Maximum	< (previous)	<= (next)

// Which ensures:
// Every subarray is counted once
// Equal elements don’t cause double counting
// Works for all edge cases: duplicates, increasing, decreasing, mixed arrays


class Solution {
public:
// for smallest subarray 
vector<int>psi(int n,vector<int>&arr){
    vector<int>ans(n);
    stack<int>st;
    ans[0]=-1;
    st.push(0);
    for(int i=1;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
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
        while(!st.empty() && arr[st.top()]>arr[i]){ // for avoid duplicate  sum here ok 
            st.pop();
        }
        ans[i]=(st.empty() ? n :st.top());
        st.push(i);
    }
    return ans;
}
// for largest subarray
vector<int>pgi(int n,vector<int>&arr){
    vector<int>ans(n);
    stack<int>st;
    ans[0]=-1;
    st.push(0);
    for(int i=1;i<n;i++){
        while(!st.empty() && arr[st.top()]<=arr[i]){
          st.pop();
        }
        ans[i]=(st.empty() ? -1:st.top());
    st.push(i);
    }
    return ans;
}
vector<int>ngi(int n,vector<int>&arr){
    vector<int>ans(n);
    stack<int>st;
    ans[n-1]=n;
    st.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && arr[st.top()]<arr[i]){ // for avoid duplicate  sum here ok 
          st.pop();
        }
        ans[i]=(st.empty()?n:st.top());
    st.push(i);
    }
    return ans;
}
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int>pevious_smaller_index=psi(n,nums);
        vector<int>next_smaller_index=nsi(n,nums);
        vector<int>pevious_greater_index=pgi(n,nums);
        vector<int>next_greater_index=ngi(n,nums);
        long long maxsum=0;
        long long minsum=0;
        for(int i=0;i<n;i++){
            int left_small=i-pevious_smaller_index[i];
            int right_small=next_smaller_index[i]-i;
            int minSum_subarray_count=left_small*right_small;
            minsum+=(nums[i]*minSum_subarray_count);
            
            int left_greater=i-pevious_greater_index[i];
            int right_greater=next_greater_index[i]-i;
            int maxSum_subarray_count=left_greater*right_greater;
            maxsum+=(nums[i]*maxSum_subarray_count);
        }
        return maxsum-minsum;
    }
};

