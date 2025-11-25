
class Solution {
  public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end()); // O(n log n)

        int h_index = 0;
        for(int i = 0; i < n; i++) {
            int h = n - i; // number of papers with citations >= citations[i]
            if(citations[i] >= h) {
                h_index = h;
                break; // since sorted, this is max possible
            }
        }
        return h_index;
    }
};


class Solution {
  public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        unordered_map<int,int>mp;

        // count frequencies
        for(int &num : citations) {
            if(num >= n) mp[n]++;
            else mp[num]++;
        }
        
        int total = 0;
        for(int i = n; i >= 0; i--) {
            total += mp[i];
            if(total >= i) return i;
        }
        return 0;
    }
};

class Solution {
  public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n+1, 0);

// Example: If a paper has 50 citations but n = 10, we treat it as >= 10. (because for h-index, citations above n don’t matter, since max h-index = n).
// Otherwise, we increment the count at count[num].
// ➡️ Now, count[i] = number of papers that have exactly i citations.
// ➡️ And count[n] = number of papers with n or more citations.
        // count frequencies
        for(int &num : citations) {
            if(num >= n) count[n]++;
            else count[num]++;
        }
        
//  We go backwards from n down to 0.
// total = number of papers that have at least i citations.
// Because as we move from high citation counts to lower ones, we keep adding up how many papers have that many citations.
// If at some point, total >= i, that means:
// There are at least i papers with at least i citations. ✅
// So i is a valid h-index, and we return it.

        int total = 0;
        for(int i = n; i >= 0; i--) {
            total += count[i];
            if(total >= i) return i;
        }
        return 0;
    }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end()); // O(n log n)
        int left = 0, right = n - 1, h_index = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int h = n - mid; // papers with citations >= citations[mid]
            if (citations[mid] >= h) {
                h_index = h;     // possible answer
                right = mid - 1; // try for smaller index (maybe larger h)
            } 
            else {
                left = mid + 1;  // need more citations, move right
            }
        }
        return h_index;
    }
};



// Time Complexity
// Counting loop: O(n)
// Backward loop: O(n)
// ➡️ Total = O(n)

// Space Complexity
// count array of size n+1.
// ➡️ O(n) extra space.

