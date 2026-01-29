class Solution {
  public:
    vector<int> diffArray(vector<int>& arr, vector<vector<int>>& opr) {
        // code here
        // diff array technique on 1D array
        int n=arr.size();
        vector<int>diff(n,0);
        for(auto &que:opr){
            int l=que[0];
            int r=que[1];
            int val=que[2];
            diff[l]+=val;
            if(r+1<n)diff[r+1]-=val;
        }
        // prefix sum from left tot right that's why start from 1
        for(int i=1;i<n;i++){
            diff[i]+=diff[i-1];
        }
        for(int i=0;i<n;i++){
            arr[i]+=diff[i];
        }
        return arr;
    }
};