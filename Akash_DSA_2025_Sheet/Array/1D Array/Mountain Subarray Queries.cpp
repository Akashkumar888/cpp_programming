
class Solution {
  public:
    vector<bool> processQueries(vector<int> &arr,vector<vector<int>> &queries) {
        int n = arr.size();
        vector<int> incEnd(n);
        vector<int> decStart(n);
        //---------------- Non-decreasing ----------------//
        incEnd[n-1] = n-1;
        for(int i=n-2;i>=0;i--){
            if(arr[i] <= arr[i+1]) incEnd[i] = incEnd[i+1];
            else incEnd[i] = i;
        }
        //---------------- Non-increasing ----------------//
        decStart[0] = 0;
        for(int i=1;i<n;i++){
            if(arr[i-1] >= arr[i]) decStart[i] = decStart[i-1];
            else decStart[i] = i;
        }
        //---------------- Queries ----------------//
        vector<bool> ans;
        for(auto &q : queries){
            int l = q[0];
            int r = q[1];
            int peak = incEnd[l];

            if(decStart[r] <= peak) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};