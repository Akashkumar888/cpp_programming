
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
    int countSubarrays(vector<int> &arr) {
        // code here
        int n=arr.size();
        int count=0;
        vector<int>nsi=nextSmallerIndex(arr);
        for(int i=0;i<n;i++){
            int right=nsi[i]-i;
            count+=right;
        }
        return count;
    }
};

// What nsi[i] Actually Represents
// nsi[i] = index of the first element to the right that is strictly smaller than arr[i].
// So valid subarrays starting at i can only go up to nsi[i] - 1.

// Number of Valid Subarrays
// Possible ending indices:

// i
// i+1
// i+2
// ...
// nsi[i]-1

// Number of choices:
// (nsi[i]-1) - i + 1
// = nsi[i] - i
// So:
// count += nsi[i] - i;
// counts all valid subarrays without including the smaller element.
