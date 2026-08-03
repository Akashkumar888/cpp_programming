
class Solution {
  public:
    bool canRepresentBST(vector<int> &arr) {
        int n=arr.size();
        stack<int> st;
        int root = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            // Current value cannot be in the left subtree
            // after we've moved to the right subtree.
            if(arr[i] < root) return false;
            
            // Move to the right subtree
            while(!st.empty() && arr[i] > st.top()) {
                root = st.top();
                st.pop();
            }
            st.push(arr[i]);
        }
        return true;
    }
};