class Solution {
  public:
  vector<int>next_smaller_index(int n,vector<int>&arr){
      vector<int>ans(n);
      ans[n-1]=n;
      stack<int>st;
      st.push(n-1);
      for(int i=n-2;i>=0;i--){
          while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
          ans[i]=(st.empty()?n:st.top());
          st.push(i);
      }
      return ans;
  }
  vector<int>prev_smaller_index(int n,vector<int>&arr){
      vector<int>ans(n);
      ans[0]=-1;
      stack<int>st;
      st.push(0);
      for(int i=1;i<n;i++){
          while(!st.empty() && arr[st.top()]>arr[i])st.pop(); //not use = for avoid duplicate
          ans[i]=(st.empty()?-1:st.top());
          st.push(i);
      }
      return ans;
  }
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        // Max of min for every window size
        //using NSR ans NSL
        // “We solve it using NSL (Next Smaller to Left) and NSR (Next Smaller to Right)”
        int n=arr.size();
        vector<int>result(n,INT_MIN);
        // The result vector is 0-indexed but window sizes go from 1 to n.
// result[k] is meant to store the maximum of minimums for window size k+1.
// So if the window length is len, we should place arr[i] at result[len-1].
        vector<int> nsi = next_smaller_index(n, arr); // NSR → Next Smaller to Right
        vector<int> psi = prev_smaller_index(n, arr); // NSL → Next Smaller to Left
        // nsi[i] → gives index of the Next Smaller Element on the Right (or n if none exists).
        // psi[i] → gives index of the Previous Smaller Element on the Left (or -1 if none exists).
        for(int i=0;i<n;i++){
            // which formula use here 
            // int len=(nsi[i]-i)*(i-psi[i]);
            int len=nsi[i]-psi[i]-1;
            result[len-1]=max(result[len-1],arr[i]);
        }
        for(int i=n-2;i>=0;i--){
            result[i]=max(result[i],result[i+1]);
        }
        // Some window sizes may not get directly updated.
// Example: maybe no element is the minimum for window size 2, but there is one for size 3.
// But logically:
// Max of Min for window size 2≥Max of Min for window size 3
// Because smaller windows always have a chance to pick a larger minimum.
        return result;
    }
};