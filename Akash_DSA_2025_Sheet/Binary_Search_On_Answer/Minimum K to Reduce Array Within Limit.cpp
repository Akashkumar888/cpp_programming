
class Solution {
public:
    bool possible(int n,vector<int>& nums,int k) {
        long long count=0;
        for(int i=0;i<n;i++){
            count += (nums[i] + k - 1) / k;
            if (count > 1LL * k * k) return false; 
        }
        return count <= 1LL * k * k;
    }
    int minimumK(vector<int>& nums) {
        int n=nums.size();
        int mx = 0;
        for (int &x : nums) mx=max(mx,x);
        int l = 1;
        int r = max(mx,(int)ceil(sqrt(n)));  

        int minAnswer = r;
        while(l<=r){
            int mid =l+(r-l)/2;
            if(possible(n,nums,mid)){
                minAnswer=mid;
                r=mid-1;    
            }
            else {
                l=mid+1;    
            }
        }
        return minAnswer;
    }
};
