
class Solution {
public:
vector<int>next_smaller_index(int n,vector<int>&arr){
      vector<int>ans(n);
      ans[n-1]=n; // for index right to left 
      stack<int>st;
      st.push(n-1); // valid index
      for(int i=n-2;i>=0;i--){
         while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
         ans[i]=(st.empty()?n:st.top());
         st.push(i);
      }
      return ans;
  }
  vector<int>previous_smaller_index(int n,vector<int>&arr){
      vector<int>ans(n);
      ans[0]=-1; // for index left to right
      stack<int>st;
      st.push(0); // valid index
      for(int i=1;i<n;i++){
         while(!st.empty() && arr[st.top()]>arr[i])st.pop(); // not use = for avoid duplicate
         ans[i]=(st.empty()?-1:st.top());
         st.push(i);
      }
      return ans;
  }
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>nsi=next_smaller_index(n,nums);
        vector<int>psi=previous_smaller_index(n,nums);
        int maxScore=0;
        for(int i=0;i<n;i++){
            int len=nsi[i]-psi[i]-1;
            // interval where nums[i] is min: [psi[i]+1, nsi[i]-1]
            if (psi[i] < k && nsi[i] > k) {          // <-- strict inequalities
                maxScore=max(maxScore,nums[i]*len);
            }
        }
        return maxScore;
    }
};



// The math / invariants
// For index i, with psi[i] = index of previous smaller element and nsi[i] = index of next smaller element, the maximal subarray where nums[i] is the minimum is:
// [ L = psi[i] + 1,  R = nsi[i] - 1 ]

// For k to be inside that interval we need:
// psi[i] + 1 <= k <= nsi[i] - 1

// which is equivalent to
// psi[i] < k  &&  nsi[i] > k
// Your code used psi[i] <= k && nsi[i] >= k, which incorrectly includes the cases psi[i] == k or nsi[i] == k — but those mean the smaller element sits at k so k is not inside the interval.
// Also use long long for the multiplication nums[i] * len to avoid overflow.