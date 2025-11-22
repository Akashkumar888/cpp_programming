
class CountingSort {
public:
    void countingSort(vector<int> &arr) {
        if (arr.empty()) return;

        int mn = *min_element(arr.begin(), arr.end());
        int mx = *max_element(arr.begin(), arr.end());

        vector<int> count(mx - mn + 1, 0);
        for (int x : arr) count[x - mn]++;

        int idx = 0;
        for (int i = 0; i < count.size(); i++) {
            while (count[i]--) {
                arr[idx++] = i + mn;
            }
        }
    }
};
