
class Solution {
public:
    bool isPossible(vector<int>& arr, int s, int x) {
        vector<long long> numbers;
        long long total = s;
        // Initial number written on the paper
        numbers.push_back(total);

        // Generate all numbers
        for (int &num : arr) {
            long long newNumber = total + num;
            numbers.push_back(newNumber);
            total += newNumber;
        }
        // Greedily find whether x can be formed
        int n=numbers.size();
        for (int i = n - 1; i >= 0; i--) {
            if (numbers[i] <= x) {
                x -= numbers[i];
            }
            if (x == 0) {
                return true;
            }
        }
        return false;
    }
};