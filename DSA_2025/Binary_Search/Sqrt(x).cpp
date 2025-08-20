
class Solution {
public:
    int mySqrt(int n) {
        long long l=1,r=n;
        long long ans=0;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(mid*mid==n)return (int)mid;
            else if(mid*mid>n)r=mid-1;
            else {
                ans=mid;
                l=mid+1;
            }
        }
        return (int)ans;
    }
};

