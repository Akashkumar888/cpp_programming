
// User function Template for C++

class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        // code here
        int n=arr.size();
        set<int>st;
        vector<int>result;
        for(int i=0;i<n;i++){
            if(st.find(arr[i])==st.end()){
                result.push_back(arr[i]);
                st.insert(arr[i]);
            }
        }
        return result;
    }
};