#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findMajority(vector<int>& arr) {
    vector<int> ans;
    int n = arr.size();
    int maj1 = -1, maj2 = -1;
    int cnt1 = 0, cnt2 = 0;

    // First pass: Find potential majority candidates
    for (int i = 0; i < n; i++) {
        if (arr[i] == maj1) {
            cnt1++;
        } else if (arr[i] == maj2) {
            cnt2++;
        } else if (cnt1 == 0) {
            maj1 = arr[i];
            cnt1 = 1;
        } else if (cnt2 == 0) {
            maj2 = arr[i];
            cnt2 = 1;
        } else {
            cnt1--;
            cnt2--;
        }
    }

    // Second pass: Verify the frequencies of the candidates
    int freq1 = 0, freq2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == maj1) {
            freq1++;
        } else if (arr[i] == maj2) {
            freq2++;
        }
    }

    int vote = n / 3;
    if (freq1 > vote) ans.push_back(maj1);
    if (freq2 > vote) ans.push_back(maj2);

    // If no majority element found, return {-1}
    if (ans.empty()) return {-1};

    // Sort results if needed
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> arr = { 2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6};
    vector<int> result = findMajority(arr);

    cout << "Majority elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
