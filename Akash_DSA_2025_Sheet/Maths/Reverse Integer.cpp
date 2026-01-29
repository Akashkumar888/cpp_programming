
class Solution {
public:
// go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.
// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
// [-2147483648 , 2147483647] then return 0.
// And you are not allowed to use 64-bit (long long).
    int reverse(int x) {
        int num=0;
        while(x!=0){
            int rem=x%10;
            x=x/10;
            // overflow check (no long long used)
            if(num>INT_MAX / 10 || (num==INT_MAX / 10 && rem>7))return 0;
            if(num<INT_MIN / 10 || (num==INT_MIN / 10 && rem<-8))return 0;
            num=num*10+rem;
        }
        return num;
    }
};