
class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        int n=arr.size();
        long long XOR=0;
        for(int &num:arr)XOR=XOR^num;
        // long long remove_rightmost_setbit =(XOR&(XOR-1));
        // long long rightmost_setbit=remove_rightmost_setbit ^ XOR;
        long long rightmost_setbit=XOR & (-XOR); // (-xor) is equal to 2's complement
        int b1=0,b2=0;
        for(int &num:arr){
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