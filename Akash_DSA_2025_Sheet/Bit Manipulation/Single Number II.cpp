
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int number=0;
        for(int bits=0;bits<=31;bits++){
            int cnt=0;
            for(int &num:nums){
                int set_bit=(1<<bits) & num;
                if(set_bit)cnt++;
            }
            if(cnt%3)number=(1<<bits) | number;
        }
        return number;
    }
};


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int k=0;k<32;k++){
            int zero=0;
            int ones=0;
            for(int &num :nums){
                if((num & (1<<k))==0){
                    zero++;
                }
                else ones++;
            }
            if(ones%3==1){
                ans = (ans | (1<<k));
            }
        }
        return ans;
    }
};