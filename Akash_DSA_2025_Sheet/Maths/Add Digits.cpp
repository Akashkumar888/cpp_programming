class Solution {
public:
int digit(int &n){
      if(n<=9)return n;
        int sum=0;
        while(n>0){
            int rem=n%10;
            sum+=rem;
            n=n/10;
        }
        return digit(sum);
  }
    int addDigits(int num) {
        // return digit(num);
        // while(num>=10){
        //     int sum=0;
        //     while(num>0){
        //         sum+=(num%10);
        //         num=num/10;
        //     }
        //     num=sum;
        // }
        // return num;
        if(num<9)return num;
        else if(num%9==0)return 9;
        return num%9;
    }
};



class Solution {
public:
    int addDigits(int num) {
        return 1+(num-1)%9;
    }
};