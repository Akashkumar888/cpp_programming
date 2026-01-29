
// Largest Rectangle in Histogram
// This is used when you want contribution of a bar as maximum in subarray sums or count subarrays where this is max
// Not for largest rectangle, because largest rectangle needs width = number of bars ≥ current bar → you need “smaller” boundary, not “greater”. 
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
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nsi=next_smaller_index(n,heights);
        vector<int>psi=previous_smaller_index(n,heights);
        int maxarea=0;
        for(int i=0;i<n;i++){
            int width=(nsi[i]-psi[i]-1);
            int height=heights[i];
            int area=width*height;
            maxarea=max(maxarea,area);
        }
      return maxarea;  
    }
};




// 👉 For each element arr[i], count how many subarrays have arr[i] as the maximum, and add its contribution.

// So the formula is: Contribution of arr[i]=arr[i]×(#of subarrays where arr[i] is max)
// On the left, you can extend until you hit a greater element (otherwise, that greater would be the max).
// On the right, you can extend until you hit a greater or equal element (to handle duplicates properly).
// So:

// prevGreater[i] = index of previous greater element (to the left).
// nextGreater[i] = index of next greater element (to the right).

// Then:
// left = i - prevGreater[i] → how many choices for the left boundary.
// right = nextGreater[i] - i → how many choices for the right boundary.

// Total subarrays where arr[i] is max: left×right
// ✅ Final Formula Contribution of arr[i]=arr[i]×(i−prevGreater[i])×(nextGreater[i]−i)
// Sum this over all i.


// 🔑 When to use left × right?
// Always when counting number of subarrays where an element is the minimum/maximum.
// Works for problems like:
// Sum of Subarray Minimums / Maximums
// Largest Rectangle in Histogram
// Product of Subarray Minimums
// ⚡ So the difference between your longest subarray problem and this sum of subarray max problem is:
// In longest subarray: you only need the length of valid subarray, so you use (nextGreater - prevGreater - 1).
// In sum of subarray maximums: you need the count of subarrays → so you multiply (i - prev) * (next - i).
