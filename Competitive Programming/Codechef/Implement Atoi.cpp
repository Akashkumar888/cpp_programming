class Solution {
public:
    int myAtoi(string &s) {
        int n = s.size();
        int sign = 1;
        int i = 0;
        // skip spaces
        while(i < n && s[i] == ' ') i++;
        // sign
        if(i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if(i < n && s[i] == '+') {
            sign = 1;
            i++;
        }
        long long num = 0;
        while(i < n){
            if(s[i] >= '0' && s[i] <= '9') num = num * 10 + s[i]-'0';
            if((sign*num) > INT_MAX )return 2147483647;
            if((sign*num) < INT_MIN)return -2147483648;
            i++;
        }
        return num * sign;
    }
};


class Solution {
public:
    int myAtoi(string &s) {
        int n = s.size();
        int sign = 1;
        int i = 0;
        // skip spaces
        while(i < n && s[i] == ' ') i++;
        // sign
        if(i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if(i < n && s[i] == '+') {
            sign = 1;
            i++;
        }
        int num = 0;
        while(i < n){
            if(s[i] < '0' || s[i] > '9') break;
            int digit = s[i] - '0';

            if(sign == 1 && (num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > 7))){
                return 2147483647;
            }

            if(sign == -1 && (num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > 8))){
                return -2147483648;
            }
            num = num * 10 + digit;
            i++;
        }
        return num * sign;
    }
};



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
