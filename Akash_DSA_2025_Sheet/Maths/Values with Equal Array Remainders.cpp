
class Solution {
public:
    int sameMod(vector<int> &arr) {
        int n = arr.size();

        // If all elements are equal, infinitely many k are possible
        int g = 0;

        for (int i = 1; i < n; i++) {
            g = gcd(g, abs(arr[i] - arr[0]));
        }

        if (g == 0)
            return -1;

        // Count divisors of g
        int count = 0;

        for (int i = 1; i * i <= g; i++) {
            if (g % i == 0) {
                count++;

                // i and g/i are two different divisors
                if (i != g / i)
                    count++;
            }
        }

        return count;
    }
};