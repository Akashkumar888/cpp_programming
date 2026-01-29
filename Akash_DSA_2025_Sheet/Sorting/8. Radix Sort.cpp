
// (non-negative integers)
class RadixSort {
public:
    void countingSort(vector<int> &arr, int exp) {
        vector<int> out(arr.size());
        int count[10] = {0};

        for (int x : arr) count[(x/exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i-1];

        for (int i = arr.size() - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;
            out[count[digit] - 1] = arr[i];
            count[digit]--;
        }
        arr = out;
    }

    void radixSort(vector<int> &arr) {
        int mx = *max_element(arr.begin(), arr.end());
        for (int exp = 1; mx / exp > 0; exp *= 10)
            countingSort(arr, exp);
    }
};
