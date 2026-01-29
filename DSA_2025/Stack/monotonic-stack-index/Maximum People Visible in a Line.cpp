
class Solution {
  public:
// A person i can see another person j if:
// height[j] < height[i],
// There is no person k standing between them such that height[k] ≥ height[i].
//Each person can see in both directions (front and back).
//Your task is to find the maximum number of people that any person can see (including themselves).
  vector<int>previousGreaterIndex(int n,vector<int>&arr){
      vector<int>result(n);
      stack<int>st;
      result[0]=-1;
      st.push(0);
      for(int i=1;i<n;i++){
          while(!st.empty() && arr[st.top()]<arr[i])st.pop();//height[j] < height[i],
          result[i]=(st.empty()?-1:st.top());
          st.push(i);
      }
      return result;
  }
  vector<int>nextGreaterIndex(int n,vector<int>&arr){
      vector<int>result(n);
      stack<int>st;
      result[n-1]=n;
      st.push(n-1);
      for(int i=n-2;i>=0;i--){
          while(!st.empty() && arr[st.top()]<arr[i])st.pop();//height[j] < height[i],
          result[i]=(st.empty()?n:st.top());
          st.push(i);
      }
      return result;
  }
    int maxPeople(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>pgi=previousGreaterIndex(n,arr);
        vector<int>ngi=nextGreaterIndex(n,arr);
        int maxDist=1;// at least the person himself
        for(int i=0;i<n;i++){
            int left=pgi[i];
            int right=ngi[i];
            int dist=ngi[i]- pgi[i] - 1;
            maxDist=max(maxDist,dist);
        }
        return maxDist;
    }
};
// So the visibility range of person i is between:
// (pgi[i] + 1)  to  (ngi[i] - 1)

// And the number of people visible including themselves is:
// ngi[i] - pgi[i] - 1
