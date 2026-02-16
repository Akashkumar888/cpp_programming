
class Solution {
  public:
    int findMinDiff(vector<int>& arr, int m) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int i=0,j=m-1;
        int minDiff=arr[j]-arr[i];
        while(j<n){
            minDiff=min(minDiff,arr[j]-arr[i]);
            i++;
            j++;
        }
        return minDiff;
    }
};