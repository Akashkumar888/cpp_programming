
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size();
        int prevCount=0;
        int currCount=1;// start from index 1 assume 1 char present 
        int count=0;
        for(int i=1;i<n;i++){
        if(s[i-1]==s[i]){
            currCount++;
        }
        else{
            count+=min(currCount,prevCount); //have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.
            prevCount=currCount;
            currCount=1;
        }
        }
        count+=min(currCount,prevCount);
        return count;
    }
};
