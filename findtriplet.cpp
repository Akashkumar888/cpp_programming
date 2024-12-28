
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<int>> findTriplets(vector<int> &arr) {
    int n = arr.size();
    unordered_map<int, vector<int>> mp; // Map to store elements and their indices
    vector<vector<int>> result;

    // Step 1: Populate the map with element values and indices
    for (int i = 0; i < n; i++) {
        mp[arr[i]].push_back(i);
    }

    // Step 2: Use nested loops to iterate over pairs of indices j and k
    for (int j = 0; j < n - 1; j++) {
        for (int k = j + 1; k < n; k++) {
            int rem = 0 - (arr[j] + arr[k]); // Calculate the required remainder
            if (mp.find(rem) != mp.end()) { // Check if rem exists in the map
                for (auto &i : mp[rem]) {
                    if (i < j) { // Ensure i < j < k
                        result.push_back({i, j, k});
                    }
                }
            }
        }
    }

    return result;
}

int main() {
    // Input array from the user
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the function to find triplets
    vector<vector<int>> triplets = findTriplets(arr);

    // Output the result
    if (triplets.empty()) {
        cout << "No triplets with zero sum found." << endl;
    } else {
        cout << "Triplets with zero sum:" << endl;
        for (const auto &triplet : triplets) {
            cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
        }
    }

    return 0;
}
