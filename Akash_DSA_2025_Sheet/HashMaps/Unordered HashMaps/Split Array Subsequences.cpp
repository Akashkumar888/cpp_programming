
class Solution {
  public:
// Each subsequence consists of consecutive integers 
//(each number is exactly one greater than the previous).
// Every subsequence has a length of at least k.
    bool isPossible(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        if (n < k) return false;

        map<int, int> count, end;
        for (int &num : arr) count[num]++;

        for (int &num : arr) {
            if (count[num] == 0) continue; // already used
            count[num]--;

            // 1️⃣ Try to extend a subsequence ending at num-1
            if (end[num - 1] > 0) {
                end[num - 1]--;
                end[num]++;
            }
            // 2️⃣ Try to start a new subsequence of length k
            else {
                bool canForm = true;
                for (int j = 1; j < k; j++) {
                    if (count[num + j] == 0) {
                        canForm = false;
                        break;
                    }
                }
                if (!canForm) return false;

                // Use up the next k-1 consecutive numbers
                for (int j = 1; j < k; j++)
                    count[num + j]--;

                // Subsequence now ends at num + k - 1
                end[num + k - 1]++;
            }
        }

        return true;
    }
};

// ✅ Conclusion
// If the problem says “split into groups of exactly k consecutive numbers” → use isPossibleDivide / isNStraightHand style.
// If the problem says “split into subsequences of length ≥ k” → use heap-based or map-based greedy approach (tracking end[num]).