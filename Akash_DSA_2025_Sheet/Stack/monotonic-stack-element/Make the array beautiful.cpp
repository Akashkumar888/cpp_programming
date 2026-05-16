
class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        int n=arr.size();
        stack<int>st;
        st.push(arr[0]);
        for(int i=1;i<n;i++){
            int curr=arr[i];
            bool removed = false;
            // if two number are have opposite sign then their value always less than 0
            // if two number are have same sign then their value always greater than 0
            while(!st.empty()){
                int top=st.top();
                bool opposite=(top>=0 && curr<0) || (top<0 && curr>=0);
                if(opposite){
                    st.pop();
                    removed=true;
                    break;
                }
                else{
                    break;
                }
            }
            if(!removed)st.push(curr);
        }
        vector<int>result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};