
class Solution {
  public:
    int getCount(int n) {
        // Remove all powers of 2
        while(n % 2 == 0){
            n = n/2;
        }
        
        int ways = 1;
        // Prime factorization of odd part
        for(int i = 3; i * i <= n; i += 2){
            int cnt = 0;
            while(n % i == 0){
                cnt++;
                n = n/i;
            }
            if(cnt > 0){
                ways = ways * (cnt + 1);
            }
        }
        
        // Remaining prime
        if(n > 1){
            ways = ways * 2;
        }
        
        // If one prime is left because exponent is 1.
        // Remove the single-number representation
        return ways - 1;
    }
};