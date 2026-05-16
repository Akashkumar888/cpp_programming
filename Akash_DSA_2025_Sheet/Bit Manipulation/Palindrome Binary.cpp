
class Solution {
  public:
    int isPallindrome(long long int N) {
        // code here
        string result="";
        while(N>0){
            result += (N % 2 == 0) ? "0" : "1"; 
            N=N>>1;
        }
        int i=0,j=result.size()-1;
        while(i<j){
            if(result[i]!=result[j])return false;
            i++,j--;
        }
        return true;
    }
};

class Solution {
public:
    int isPallindrome(long long int N) {
        long long original = N;
        long long rev = 0;

        while(N > 0){
            rev = (rev << 1) | (N & 1);
            N = N >> 1;
        }

        return original == rev;
    }
};


class Solution {
public:
    int isPallindrome(long long int N) {

        int left = 63;
        int right = 0;

        // find highest set bit
        while(left >= 0 && ((N >> left) & 1) == 0) left--;

        while(left > right){
            int lbit = (N >> left) & 1;
            int rbit = (N >> right) & 1;

            if(lbit != rbit) return false;

            left--;
            right++;
        }

        return true;
    }
};