
class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        // code here
        int m=arr1.size();
        int n=arr2.size();
        int i=0,j=n-1;
        int minDiff=INT_MAX;
        int first=-1,second=-1;
        while(i<m && j>=0){
            int sum=(arr1[i]+arr2[j]);
            if(abs(x-sum)<minDiff){
                minDiff=abs(x-sum);
                first=arr1[i];
                second=arr2[j];
            }
            if(sum<x)i++;
            else if(sum>=x) j--;
        }
        return {first,second};
    }
};