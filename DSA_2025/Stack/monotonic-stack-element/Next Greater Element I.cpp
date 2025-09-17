
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m=nums2.size();// set 
        int n=nums1.size();// subset of nums2 
        unordered_map<int,int>mp;
        stack<int>st;
        mp[nums2[m-1]]=-1;
        st.push(nums2[m-1]);
        for(int i=m-2;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            mp[nums2[i]]=(st.empty()?-1:st.top());
            st.push(nums2[i]);
        }
        vector<int>result(n);
        for(int i=0;i<n;i++){
            result[i]=mp[nums1[i]];
        }
        return result;
    }
};

