
#include <bits/stdc++.h>
using namespace std;

long countSubarraysWithXOR(vector<int>& arr, int k) {
    long count = 0;
    long XOR = 0;
    unordered_map<int, int> freqMap;
    freqMap[0] = 1; // Initialize to handle cases where XOR equals k at the start

    for (int& num : arr) {
        XOR ^= num;
        if (freqMap.find(XOR ^ k) != freqMap.end()) {
            count += freqMap[XOR ^ k];
        }
        freqMap[XOR]++;
    }

    return count;
}

int main() {
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    cout << "Count of subarrays with XOR " << k << " is: " 
         << countSubarraysWithXOR(arr, k) << endl;
    return 0;
}
