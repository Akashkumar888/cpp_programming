
class Solution {
  public:
    int minToggle(vector<int>& arr) {
        int n=arr.size();
        vector<int>prefixOne(n,0);
        vector<int>suffixZero(n,0);

        if(arr[0]==1)prefixOne[0]=1;

        for(int i=1;i<n;i++){
            prefixOne[i]=prefixOne[i-1];
            if(arr[i]==1){
                prefixOne[i]++;
            }
        }

        if(arr[n-1]==0)suffixZero[n-1]=1;

        for(int i=n-2;i>=0;i--){
            suffixZero[i]=suffixZero[i+1];
            if(arr[i]==0){
                suffixZero[i]++;
            }
        }

        int minToggle=INT_MAX;

        for(int i=0;i<n;i++){
            int leftOnes=0;
            int rightZeros=0;
            if(i>0){
                leftOnes=prefixOne[i-1];
            }
            rightZeros=suffixZero[i];
            minToggle=min(minToggle, leftOnes+rightZeros);
        }

        // all 0s
        minToggle=min(minToggle,prefixOne[n-1]);

        // all 1s
        minToggle=min(minToggle,suffixZero[0]);

        return minToggle;
    }
};