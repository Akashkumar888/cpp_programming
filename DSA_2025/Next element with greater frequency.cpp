
class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>ans(n);
        unordered_map<int,int>mp;
        for(int &num:arr)mp[num]++;
        stack<pair<int,int>>st;
        ans[n-1]=-1;
        st.push({arr[n-1],mp[arr[n-1]]});
        for(int i=n-2;i>=0;i--){
            while(!st.empty() &&  st.top().second<=mp[arr[i]])st.pop();
            // while(!st.empty() &&  mp[st.top().first]<=mp[arr[i]])st.pop();
            ans[i]=(st.empty()?-1:st.top().first);
            st.push({arr[i],mp[arr[i]]});
        }
        return ans;
    }
};


// ⏱ Time Complexity:
// Building frequency map: O(n)
// Main loop (reverse traversal): Each element is pushed and popped at most once in the stack.
// So, stack operations: amortized O(n)
// So total time: O(n)

// 💾 Space Complexity:
// Frequency map: O(n) (in worst case, all elements are unique)
// Stack: O(n) (in worst case, strictly decreasing frequencies)
// So overall space: O(n)


