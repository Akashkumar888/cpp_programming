
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int hIndex(vector<int>& citations) {
    int n = citations.size();
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        if (citations[i] >= n) mp[n]++;
        else mp[citations[i]]++;
    }

    int idx = n; // Start from the maximum possible H-Index
    int num = mp[n]; // Papers with citations >= n
    while (num < idx) { // Check if num >= idx condition is satisfied
        idx--;
        num += mp[idx];
    }

    return idx; // Return the calculated H-Index
}

int main() {
    vector<int> citations = {3, 0, 6, 1, 5};
    cout << "H-Index: " << hIndex(citations) << endl;
    return 0;
}
