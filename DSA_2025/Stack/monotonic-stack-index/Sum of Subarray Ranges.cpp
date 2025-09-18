
class Solution {
public:
// for smallest subarray 
vector<int>psi(int n,vector<int>&arr){
    vector<int>ans(n);
    stack<int>st;
    ans[0]=-1;
    st.push(0);
    for(int i=1;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        ans[i]=(st.empty()?-1:st.top());
        st.push(i);
    }
    return ans;
}
vector<int>nsi(int n,vector<int>&arr){
    vector<int>ans(n);
    stack<int>st;
    ans[n-1]=n;
    st.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && arr[st.top()]>arr[i]){ // for avoid duplicate  sum here ok 
            st.pop();
        }
        ans[i]=(st.empty() ? n :st.top());
        st.push(i);
    }
    return ans;
}
// for largest subarray
vector<int>pgi(int n,vector<int>&arr){
    vector<int>ans(n);
    stack<int>st;
    ans[0]=-1;
    st.push(0);
    for(int i=1;i<n;i++){
        while(!st.empty() && arr[st.top()]<=arr[i]){
          st.pop();
        }
        ans[i]=(st.empty() ? -1:st.top());
    st.push(i);
    }
    return ans;
}
vector<int>ngi(int n,vector<int>&arr){
    vector<int>ans(n);
    stack<int>st;
    ans[n-1]=n;
    st.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && arr[st.top()]<arr[i]){ // for avoid duplicate  sum here ok 
          st.pop();
        }
        ans[i]=(st.empty()?n:st.top());
    st.push(i);
    }
    return ans;
}
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int>pevious_smaller_index=psi(n,nums);
        vector<int>next_smaller_index=nsi(n,nums);
        vector<int>pevious_greater_index=pgi(n,nums);
        vector<int>next_greater_index=ngi(n,nums);
        long long maxsum=0;
        long long minsum=0;
        for(int i=0;i<n;i++){
            int left_small=i-pevious_smaller_index[i];
            int right_small=next_smaller_index[i]-i;
            int minSum_subarray_count=left_small*right_small;
            minsum+=(nums[i]*minSum_subarray_count);
            
            int left_greater=i-pevious_greater_index[i];
            int right_greater=next_greater_index[i]-i;
            int maxSum_subarray_count=left_greater*right_greater;
            maxsum+=(nums[i]*maxSum_subarray_count);
        }
        return maxsum-minsum;
    }
};

