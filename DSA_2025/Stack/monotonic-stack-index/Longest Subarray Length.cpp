
class Solution {
  public:
  vector<int>next_greater_index(int n,vector<int>&arr){
      vector<int>ans(n);
      ans[n-1]=n; // for index right to left 
      stack<int>st;
      st.push(n-1); // valid index
      for(int i=n-2;i>=0;i--){
         while(!st.empty() && arr[st.top()]<=arr[i])st.pop();
         ans[i]=(st.empty()?n:st.top());
         st.push(i);
      }
      return ans;
  }
  vector<int>previous_greater_index(int n,vector<int>&arr){
      vector<int>ans(n);
      ans[0]=-1; // for index left to right
      stack<int>st;
      st.push(0); // valid index
      for(int i=1;i<n;i++){
         while(!st.empty() && arr[st.top()]<arr[i])st.pop(); // not use = for avoid duplicate
         ans[i]=(st.empty()?-1:st.top());
         st.push(i);
      }
      return ans;
  }
    int longestSubarray(vector<int>& arr) {
        // code here
        // all the elements of the subarray are smaller 
        // than or equal to the length of the subarray
        // We need the longest subarray length L such that every element inside that subarray ≤ L.
        // Subarray = contiguous portion of the array.
        // Condition = max(subarray) ≤ length(subarray).
        // max(subarray) that's why we use ngi and pgi 
        int n=arr.size();
        vector<int>ngi=next_greater_index(n,arr);
        vector<int>pgi=previous_greater_index(n,arr);
        int count=0,maxlen=0;
        for(int i=0;i<n;i++){
            // int left=(i-pgi[i]);
            // int right=(ngi[i]-i);
            // int len=left*right;
            int len = ngi[i] - pgi[i] - 1; // correct formula
            if(arr[i]<=len){
                maxlen=max(maxlen, len);
            }
        }
        return maxlen;
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


// 1️⃣ Identify the type of problem
// When you see an array question, ask yourself:
// Are we counting subarrays?
// Example: Sum of subarray minimums / maximums, number of subarrays where arr[i] is max/min.
// ✅ Use: left × right = (i - prev) * (next - i)
// Reason: left = number of choices for left boundary, right = number of choices for right boundary → multiply to get total subarrays including arr[i].
// Are we finding a range or largest/smallest segment?
// Example: Longest subarray under a condition, Largest Rectangle in Histogram.
// ✅ Use: width = (next - prev - 1)
// Reason: You want contiguous length, not count of all subarrays.
// Rule of thumb:
// “Max contribution” problem → use NGI/PGI
// “Min contribution” problem → use NSI/PSI
// “Length/range” problem → use (next - prev - 1)
// “Count of subarrays” → use (i - prev) * (next - i)

// 3️⃣ How to recognize in OA interviews
// Look at the problem statement keywords:
// Length / Largest / Longest → think rectangle or contiguous length → (next-prev-1)
// Example: Largest Rectangle in Histogram, Longest Subarray where max ≤ L
// Sum / Count / Contribution / Total → think all subarrays including this element → left * right
// Example: Sum of subarray maximums, Sum of subarray minimums
// Condition on min/max → check whether the condition is based on >= or <=

// 4️⃣ Quick Examples
// Example 1: Largest Rectangle in Histogram
// Want largest area → length matters → (NSI - PSI - 1) * height[i]
// Use smaller indices because rectangle stops when bar is smaller.
// Example 2: Sum of subarray maximums
// Want sum of all subarray maxes → count of subarrays matters → (i - prevGreater) * (nextGreater - i) * arr[i]
// Use greater indices because arr[i] must be the max → stop when a bigger bar is found.
// Example 3: Longest subarray where max ≤ length
// Want length → (NGI - PGI - 1)
// Use greater indices because the subarray breaks when a bigger element occurs.

// 5️⃣ How to memorize
// Simple mnemonic:
// Rectangle / Length → NSI/PSI if height matters
// Subarray sum / count → NGI/PGI if max, NSI/PSI if min
// Length of longest valid → next-prev-1
// Count of subarrays → left * right