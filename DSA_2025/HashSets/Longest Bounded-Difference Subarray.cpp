
class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        vector<int>ans;
        int i=0,j=0;
        int start = 0, end = -1;  // ✅ fixed initialization
        int maxlen=0;
        multiset<int>st;
        while(j<n){
           st.insert(arr[j]);
           while((*st.rbegin()-*st.begin())>x){
           st.erase(st.find(arr[i]));
           i++;
           }
           // update best answer here (after fixing window)
           if(j-i+1>maxlen || (j-i+1==maxlen && i<start)){
               start=i;
               end=j;
               maxlen=max(maxlen,j-i+1);
           }
           j++;
        }
        for(int k=start;k<=end;k++)ans.push_back(arr[k]);
        return ans;
    }
};
