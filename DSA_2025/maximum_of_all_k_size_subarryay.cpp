
#include <bits/stdc++.h>
using namespace std;

vector<int> maxOfSubarrays(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> ans;
    deque<int> dq;

    for (int i = 0; i < n; i++) {
        // Remove elements that are out of the window
        if (!dq.empty() && dq.front() <= i - k) dq.pop_front();

        // Maintain a decreasing order in deque
        while (!dq.empty() && arr[i] > arr[dq.back()]) dq.pop_back();

        // Push current index
        dq.push_back(i);

        // Start storing results once we have a full window
        if (i >= k - 1) {
            ans.push_back(arr[dq.front()]);
        }
    }

    return ans;
}

// Driver code
int main() {
    vector<int> arr = {1, 3, 2, 5, 8, 7, 9, 6};
    int k = 3;
    vector<int> result = maxOfSubarrays(arr, k);
    
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}

