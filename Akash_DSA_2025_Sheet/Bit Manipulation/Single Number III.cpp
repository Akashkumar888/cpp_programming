
// class Solution {
// public:
//     vector<int> singleNumber(vector<int>& nums) {
//         long long  XOR=0;
//       for(int &num :nums){
//         XOR^=num;
//       }  
//       int mask=(XOR) & (-XOR); // (-xor) is equal to 2's complement
//       int groupa=0;
//       int groupb=0;
//       for(int &num:nums){
//         if(mask & num){
//             groupa^=num;
//         }
//         else{
//             groupb^=num;
//         }
//       }
//       return {groupa,groupb};
//     }
// };


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        long long XOR=0;
        for(int &num:nums)XOR=XOR^num;
        // long long remove_rightmost_setbit =(XOR&(XOR-1));
        // long long rightmost_setbit=remove_rightmost_setbit ^ XOR;
        long long rightmost_setbit=XOR & (-XOR); // (-xor) is equal to 2's complement
        int b1=0,b2=0;
        for(int &num:nums){
            if((num & rightmost_setbit)!=0){
                b1=b1^num;
            }
            else{
                b2=b2^num;
            }
        }
        if(b1<b2)return {b1,b2};
        return {b2,b1};
    }
};
