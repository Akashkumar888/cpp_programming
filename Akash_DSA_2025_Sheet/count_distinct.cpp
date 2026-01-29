
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> countDistinct(vector<int> &arr, int k) {
    vector<int> ans;            // Result to store distinct counts
    unordered_map<int, int> mp; // HashMap to maintain frequency of elements
    int n = arr.size();
    int i = 0, j = 0;

    // Process the first window of size k
    while (j < k) {
        mp[arr[j]]++; // Increment the frequency of the current element
        j++;
    }

    // Add the count of distinct elements in the first window
    ans.push_back(mp.size());

    // Process the rest of the array
    while (j < n) {
        // Add the new element to the window
        mp[arr[j]]++;

        // Remove the first element of the previous window
        mp[arr[i]]--;
        if (mp[arr[i]] == 0) {
            mp.erase(arr[i]); // Remove the element if its frequency becomes 0
        }

        // Slide the window forward
        i++;
        j++;

        // Add the count of distinct elements in the current window
        ans.push_back(mp.size());
    }

    return ans;
}

int main() {
    int n, k;

    // Input array size and window size
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the window size: ";
    cin >> k;

    vector<int> arr(n);

    // Input the array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the function
    vector<int> result = countDistinct(arr, k);

    // Output the result
    cout << "Count of distinct elements in every window of size " << k << ": ";
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
