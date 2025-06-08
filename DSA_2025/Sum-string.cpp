
class Solution {
public:
    // Helper to add two string numbers
    string addStrings(const string &num1, const string &num2) {
        string result = "";
        int carry = 0, i = num1.size() - 1, j = num2.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            result += (sum % 10 + '0');
            carry = sum / 10;
        }

        reverse(result.begin(), result.end());
        return result;
    }

    // Recursive Fibonacci-style check
    bool isValidFibonacci(const string &first, const string &second, const string &remaining) {
        string third = addStrings(first, second);
        if (third == remaining) return true;
        if (remaining.size() < third.size() || remaining.substr(0, third.size()) != third) return false;

        return isValidFibonacci(second, third, remaining.substr(third.size()));
    }

    bool isSumString(string &s) {
        int n = s.size();
        for (int i = 1; i < n; ++i) {
            string first = s.substr(0, i);
            if (first.size() > 1 && first[0] == '0') continue; // No leading 0s

            for (int j = 1; i + j < n; ++j) {
                string second = s.substr(i, j);
                if (second.size() > 1 && second[0] == '0') continue;

                string remaining = s.substr(i + j);
                if (isValidFibonacci(first, second, remaining)) return true;
            }
        }
        return false;
    }
};

