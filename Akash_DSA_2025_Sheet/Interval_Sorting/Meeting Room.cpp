
class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-1;i++){
            if(arr[i][1]>arr[i+1][0])return false;//A person can attend a meeting if its starting time is greater than or equal to the previous meeting's ending time.
        }
        return true;
    }
};