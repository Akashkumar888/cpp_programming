
class Solution {
public:
    double solve(double b, long e) {
        if (e == 0) return 1.0;  
        if (e < 0) return solve(1 / b, -e);  
        if (e % 2 == 0) return solve(b * b, e / 2);  
        return b * solve(b * b, (e - 1) / 2);  
    }

    double power(double b, int e) {
        return solve(b, long(e));  
    }
};
