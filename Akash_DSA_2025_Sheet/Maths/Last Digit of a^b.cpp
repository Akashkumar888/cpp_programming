
class Solution {
  public:
    int getLastDigit(string& a, string& b) {
        // code here
        int n=b.size();
        int num2;
        if(n == 1){
            num2 = b[0] - '0';
            if(num2==0)return 1;
        }
        else{
            num2 = (b[n-2]-'0')*10 + (b[n-1]-'0');
        }
        int rem2 = num2 % 4;
        if(num2==0 || rem2==0)rem2=4;
        
        int m=a.size();
        int num1 = a[m-1] - '0';
        
        int powerOfValue=(pow(num1,rem2));
        return powerOfValue%10;
    }
};



class Solution {
  public:
  long long powerOfAtoB(long long a, long long b){
    long long ans = 1;
    while(b > 0){
        if(b & 1){
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}
    int getLastDigit(string& a, string& b) {
        // code here
        int n=b.size();
        int num2;
        if(n == 1){
            num2 = b[0] - '0';
            if(num2==0)return 1;
        }
        else{
            num2 = (b[n-2]-'0')*10 + (b[n-1]-'0');
        }
        int rem2 = num2 % 4;
        if(num2==0 || rem2==0)rem2=4;
        
        int m=a.size();
        int num1 = a[m-1] - '0';
        
        int powerOfValue=(powerOfAtoB(num1,rem2));
        return powerOfValue%10;
    }
};
