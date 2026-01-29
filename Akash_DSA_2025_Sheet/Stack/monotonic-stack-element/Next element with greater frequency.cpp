
class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>ans(n);
        unordered_map<int,int>mp;
        for(auto &num:arr)mp[num]++;
        stack<pair<int,int>>st;
        ans[n-1]=-1;
        st.push({arr[n-1],mp[arr[n-1]]});
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && mp[arr[i]]>=st.top().second)st.pop();
            ans[i]=(st.empty()?-1:st.top().first);
            st.push({arr[i],mp[arr[i]]});
        }
        return ans;
    }
};


class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>ans(n);
        unordered_map<int,int>mp;
        for(auto &num:arr)mp[num]++;
        stack<int>st;
        ans[n-1]=-1;
        st.push(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && mp[arr[i]]>=mp[st.top()])st.pop();
            ans[i]=(st.empty()?-1:st.top());
            st.push(arr[i]);
        }
        return ans;
    }
};
