
class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        int n=s.size();
        int maxLen=-1;
        vector<int>firstOccurence(26,-1);
        for(int i=0;i<n;i++){
            if(firstOccurence[s[i]-'a']==-1){
                firstOccurence[s[i]-'a']=i;
            }
            else{
                maxLen=max(maxLen,i-firstOccurence[s[i]-'a']-1);
            }
        }
        return maxLen;
    }
};