class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            int rem = num % 10;
            sum += rem;
            num = num / 10;
        }
        return sum;
    }
    int findMax(int n) {
        string s = to_string(n);
        int ans = n;
        for (int i = 0; i < s.length(); i++) {
            // We cannot decrease 0
            if (s[i] == '0') continue;
            string temp = s;
            // Decrease current digit by 1
            temp[i]--;

            // Make all digits after it 9
            for (int j = i + 1; j < temp.length(); j++) {
                temp[j] = '9';
            }
            int candidate = stoi(temp);
            // We want the number having maximum digit sum.
            // In case of equal digit sum, larger number.
            if (digitSum(candidate) > digitSum(ans) || (digitSum(candidate) == digitSum(ans) && candidate > ans)) {
                ans = candidate;
            }
        }
        return ans;
    }
};