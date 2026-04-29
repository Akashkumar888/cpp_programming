// User function Template for C++

class Solution {
  public:
    int profit(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        stack<int>st;
        st.push(arr[0]);
        int totalProfit=0;
        for(int i=1;i<n;i++){
            while(!st.empty() && st.top()<=arr[i]){
                totalProfit+=abs(arr[i]-st.top());
                st.pop();
            }
            st.push(arr[i]);
        }
        while(!st.empty()){
            totalProfit+=(st.top());
            st.pop();
        }
        return totalProfit;
    }
};
