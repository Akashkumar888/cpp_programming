
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int MOD=1e9+7;
        vector<int>ans;
        vector<int> powers;
        int power = 1; // Start from 2^0 = 1
        while (n > 0) {
            if (n & 1) { // If current bit is set
                powers.push_back(power);
            }
            power <<= 1; // Move to next power of 2
            n >>= 1;     // Check next bit
        }
        vector<long long>preSum(powers.size(),1);
        preSum[0]=powers[0];
        for(int i=1;i<powers.size();i++){
            preSum[i]=1LL*(preSum[i-1] * powers[i]);
        }
        for(auto &query:queries){
            int left=query[0];
            int right=query[1];
            long long num;
            if (left==0)num=(preSum[right]); 
            else num=(preSum[right]/preSum[left-1]); // +MOD to avoid negative
            ans.push_back((int)(num % MOD));
        }
        return ans;
    }
};

