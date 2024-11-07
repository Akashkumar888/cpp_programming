
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class RangeFreqQuery {
public:
    vector<unordered_map<int, int>> seg;

    unordered_map<int, int> addmap(unordered_map<int, int>& mp1, unordered_map<int, int>& mp2) {
        unordered_map<int, int> mp;
        for (auto& it : mp1) {
            mp.insert(it);
        }
        for (auto& it : mp2) {
            int key = it.first;
            int value = it.second;
            if (mp.find(key) != mp.end()) {
                mp[key] += value;
            } else {
                mp.insert(it);
            }
        }
        return mp;
    }

    void buildtree(vector<int>& arr, int i, int lo, int hi) {
        if (lo == hi) {
            int key = arr[lo];
            int val = 1;
            seg[i].insert({key, val});
            return;
        }
        int mid = lo + (hi - lo) / 2;
        buildtree(arr, 2 * i + 1, lo, mid);
        buildtree(arr, 2 * i + 2, mid + 1, hi);
        seg[i] = addmap(seg[2 * i + 1], seg[2 * i + 2]);
    }

    int getfreq(int i, int lo, int hi, int& l, int& r, int& val) {
        if (r < lo || hi < l) {
            return 0;
        }
        if (lo >= l && hi <= r) {
            if (seg[i].find(val) == seg[i].end()) return 0;
            else return seg[i][val];
        }
        int mid = lo + (hi - lo) / 2;
        int leftfreq = getfreq(2 * i + 1, lo, mid, l, r, val);
        int rightfreq = getfreq(2 * i + 2, mid + 1, hi, l, r, val);
        return leftfreq + rightfreq;
    }

    int n;
    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        seg.resize(4 * n);
        buildtree(arr, 0, 0, n - 1);
    }

    int query(int left, int right, int value) {
        return getfreq(0, 0, n - 1, left, right, value);
    }
};

int main() {
    // Test case
    vector<int> arr = {1, 3, 3, 2, 3, 1}; // Initialize array
    RangeFreqQuery* obj = new RangeFreqQuery(arr);

    // Query for frequency of 3 between indices 1 and 4
    cout << "Frequency of 3 between indices 1 and 4: " << obj->query(1, 4, 3) << endl; // Output: 2

    // Query for frequency of 1 between indices 0 and 5
    cout << "Frequency of 1 between indices 0 and 5: " << obj->query(0, 5, 1) << endl; // Output: 2

    // Query for frequency of 2 between indices 2 and 3
    cout << "Frequency of 2 between indices 2 and 3: " << obj->query(2, 3, 2) << endl; // Output: 1

    // Clean up memory
    delete obj;

    return 0;
}
