
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>result(n);
        stack<int>st;
        st.push(0);
        result[0]=1;
        for(int i=1;i<n;i++){
            while(!st.empty() && arr[st.top()]<=arr[i])st.pop();
            result[i]=(st.empty()?(i+1):i-st.top());
            st.push(i);
        }
        return result;
    }
};