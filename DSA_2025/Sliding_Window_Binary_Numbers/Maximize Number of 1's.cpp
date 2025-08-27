
class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        // Here you allow at most k zeros in the window.
       // So if k = 2, window can contain 0, 1, or 2 zeros.
        int n=arr.size();
        int maxLen=0;
        int i=0,j=0;
        int countZero=0;
        while(j<n){
            if(arr[j]==0)countZero++;
            while(countZero>k){// k se ek zyada count 
                if(arr[i]==0)countZero--;
                i++;
            }
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};


// So if k = 2, window can contain 0, 1, or 2 zeros.
// Works fine for “flip at most k zeros” problems.
// Time: O(n)
// Space: O(1)

