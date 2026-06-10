
class Solution {
  public:// Find the maximum difference of the number of 0s and the number of 1s (number of 0s – number of 1s) in a substring of the string.
    int maxSubstring(string &s) {
        // code here
        int n=s.size();
        int maxDiff=0;
        int sum=0;
        for(char &ch:s){
            if(ch=='1')sum-=1; 
            else sum+=1;
            maxDiff=max(maxDiff,sum);
            if(sum<0)sum=0;
        }
        return maxDiff==0 ? -1 : maxDiff;
    }
};

