
// (for floating or uniformly distributed values)
class BucketSort {
public:
    void bucketSort(vector<float> &arr) {
        int n = arr.size();
        vector<vector<float>> bucket(n);

        for (float v : arr) {
            int idx = v * n;   
            bucket[idx].push_back(v);
        }

        for (int i = 0; i < n; i++)
            sort(bucket[i].begin(), bucket[i].end());

        int k = 0;
        for (int i = 0; i < n; i++)
            for (float v : bucket[i])
                arr[k++] = v;
    }
};
