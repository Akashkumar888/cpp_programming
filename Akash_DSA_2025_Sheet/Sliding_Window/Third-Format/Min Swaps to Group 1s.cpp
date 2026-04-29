
class Solution {
public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        int ones = 0;
        for (int &num : arr) {
            if (num == 1) ones++;
        }
        if(ones==0)return -1;
        int k = ones;
        // count zeros in first window
        int zeroCount = 0;
        int j=0;
        while (j < k) {
            if(arr[j] == 0)zeroCount++;
            j++;
        }
        int minSwap = zeroCount;
        int i=0;
        while (j<n){
            // add new element
            if (arr[j] == 0) zeroCount++;
            
            // remove old element
            if (arr[i] == 0) zeroCount--;
            
            minSwap = min(minSwap, zeroCount);
            j++;
            i++;
        }
        return minSwap;
    }
};