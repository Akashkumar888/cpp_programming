
class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        long long reachable = 1;
        for(int i=0;i<n;i++){
            // gap found
            if(arr[i] > reachable){
                return reachable;
            }
            // extend range
            reachable += arr[i];
        }
        return reachable;
    }
};