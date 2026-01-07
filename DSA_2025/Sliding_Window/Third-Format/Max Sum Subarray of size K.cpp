
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int i=0,j=0;
        int sum=0,maxSum=0;
        while(j<n){
            sum+=arr[j];
            if(j-i+1==k){
                maxSum=max(maxSum,sum);
                sum-=arr[i];
                i++;
            }
            j++;
        }
        return maxSum;
    }
};


class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        long  maxsum=0;
        int i=0,j=0;
        long sum=0;
        while(j<N){
            sum+=Arr[j];
            if(j>=K){
                sum-=Arr[i];
                i++;
            }
            maxsum=max(maxsum,sum);
            j++;
        }
        return (maxsum);
    }
};

