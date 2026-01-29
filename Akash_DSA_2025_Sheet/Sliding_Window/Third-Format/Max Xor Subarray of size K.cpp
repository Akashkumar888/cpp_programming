
class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int i=0,j=0;
        int Xor=0,maxXor=0;
        while(j<n){
            Xor^=arr[j];
            if(j-i+1==k){
                maxXor=max(maxXor,Xor);
                Xor^=arr[i];
                i++;
            }
            j++;
        }
        return maxXor;
    }
};
