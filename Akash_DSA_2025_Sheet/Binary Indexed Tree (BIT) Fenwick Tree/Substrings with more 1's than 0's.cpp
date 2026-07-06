
class Solution {
public:
    // Fenwick Tree (Binary Indexed Tree)
    class BIT {
    public:
        vector<int> bit;
        int n;

        BIT(int sz) {
            n = sz;
            bit.assign(n + 1, 0);
        }

        // Add value at index
        void update(int idx, int val) {
            while(idx <= n) {
                bit[idx] += val;
                idx += idx & (-idx);
            }
        }

        // Returns frequency from 1...idx
        int query(int idx) {
            int sum = 0;
            while(idx > 0) {
                sum += bit[idx];
                idx -= idx & (-idx);
            }
            return sum;
        }
    };
    int lowerBound(vector<int> &temp, int x){
        int low = 0;
        int high = temp.size() - 1;
        int ans = temp.size();
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(temp[mid] >= x){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    int countSubstring(string &s) {
        int n = s.size();
        // Prefix sums
        vector<int> prefix(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            if(s[i - 1] == '1'){
                prefix[i] = prefix[i - 1] + 1;
            }
            else{
                prefix[i] = prefix[i - 1] - 1;
            }
        }

        // Coordinate Compression
        vector<int> temp = prefix;
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());

        BIT bit(temp.size());

        long long ans = 0;

        for(int &x : prefix) {

            // Find compressed index
            int idx = lowerBound(temp,x) + 1;

            // Count previous prefix sums strictly smaller
            ans += bit.query(idx - 1);

            // Insert current prefix
            bit.update(idx, 1);
        }
        return ans;
    }
};