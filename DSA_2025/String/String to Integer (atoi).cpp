
class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        long long sum = 0;
        bool minusSign = false;
        int i = 0;

        // Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        // If string ended
        if (i == n) return 0;

        // Check sign
        if (s[i] == '-') {
            minusSign = true;
            i++;
        }
        else if (s[i] == '+') {
            i++;
        }

        // Convert digits
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            sum = sum * 10 + digit;

            // Overflow check
            if (minusSign==false && sum > INT_MAX) return INT_MAX;
            if (minusSign==true && -sum < INT_MIN) return INT_MIN;

            i++;
        }

        if (minusSign) sum = -sum;
        return (int)sum;
    }
};
