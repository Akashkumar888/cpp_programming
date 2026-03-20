
class Solution {
  public:
  vector<int>nextSmallerIndex(vector<int>&arr){
      int n=arr.size();
      vector<int>result(n);
      stack<int>st;
      st.push(n-1);
      result[n-1]=n;
      for(int i=n-2;i>=0;i--){
          while(!st.empty() && arr[st.top()]>=arr[i]){
              st.pop();
          }
          result[i]=(st.empty()?n:st.top());
          st.push(i);
      }
      return result;
  }
  vector<int>previousSmallerIndex(vector<int>&arr){
      int n=arr.size();
      vector<int>result(n);
      stack<int>st;
      st.push(0);
      result[0]=-1;
      for(int i=1;i<n;i++){
          while(!st.empty() && arr[st.top()]>arr[i]){// avoid duplicate index for psi and nsi
              st.pop();
          }
          result[i]=(st.empty()?-1:st.top());
          st.push(i);
      }
      return result;
  }
    int sumSubMins(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>nsi=nextSmallerIndex(arr);
        vector<int>psi=previousSmallerIndex(arr);
        long long sum = 0;
        int MOD = 1e9+7;
        for(int i=0;i<n;i++){
            long long left=i-psi[i];
            long long right=nsi[i]-i;
            long long contribution=(left*right)%MOD;
            contribution=(contribution*arr[i])%MOD;
            sum=(sum+contribution)%MOD;
        }
        return sum;
    }
};