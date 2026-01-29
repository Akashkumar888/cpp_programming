
class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0)return 0;
        int maxNumber=0;
        vector<int>nums(n+1,0);
        nums[0]=0;
        nums[1]=1;
        maxNumber=max(nums[0],nums[1]);
        for(int i=0;i<=min(n/2,(n-1)/2);i++){
        if(2<=2*i && 2*i<=n){
        nums[2*i]=nums[i];
        maxNumber=max(maxNumber,nums[2*i]);
        }
        if(2<=2*i+1 && 2*i+1<=n){
        nums[2*i+1]=nums[i]+nums[i+1];
        maxNumber=max(maxNumber,nums[2*i+1]);
        }
        }
        return maxNumber;
    }
};


class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0)return 0;
        int maxNumber=0;
        vector<int>nums(n+1,0);
        nums[1]=1;
        maxNumber=max(nums[0],nums[1]);
        for(int i=1;i<=min(n/2,(n-1)/2);i++){
        nums[2*i]=nums[i];
        maxNumber=max(maxNumber,nums[2*i]);
        nums[2*i+1]=nums[i]+nums[i+1];
        maxNumber=max(maxNumber,nums[2*i+1]);
        }
        return maxNumber;
    }
};
