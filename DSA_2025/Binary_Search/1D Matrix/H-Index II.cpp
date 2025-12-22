
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
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


