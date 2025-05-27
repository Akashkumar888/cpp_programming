
class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        // code here
        int n=preorder.size();
        vector<int>ans;
        // bst follow own property then use monotonic stack
        stack<int>st;
        st.push(preorder[0]);
        for(int i=1;i<n;i++){
            if(!st.empty() && st.top()>preorder[i])st.push(preorder[i]);
            else{
                int temp=st.top();
                int count=0;
                while(!st.empty() && st.top()<preorder[i]){
                    st.pop();
                    count++;
                }
                st.push(preorder[i]);
                 // The last node before right subtree is always a leaf
            if(count>=2)ans.push_back(temp);
            }
        }
        // Last node in preorder is always a leaf
        ans.push_back(st.top());
        return ans;
    }
};


