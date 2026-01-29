
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



class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>ans(n);
        unordered_map<int,int>mp;
        for(int &num:arr)mp[num]++;
        stack<int>st;
        ans[n-1]=-1;
        st.push(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() &&  mp[st.top()]<=mp[arr[i]])st.pop();
            ans[i]=(st.empty()?-1:st.top());
            st.push(arr[i]);
        }
        return ans;
    }
};

// ⏱ Time Complexity:
// Building frequency map: O(n)
// Main loop (from n-2 to 0):
// Every element is pushed and popped at most once from the stack.
// So, all stack operations: O(n) amortized.
// Total Time Complexity: O(n)

// 💾 Space Complexity:
// Frequency map: O(n) — in worst case (all elements distinct).
// Stack: O(n) — in worst case (monotonic decreasing frequency).
// Answer vector: O(n)
// Total Space Complexity: O(n)

