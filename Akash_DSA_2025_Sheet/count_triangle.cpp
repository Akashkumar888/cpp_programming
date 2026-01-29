
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countTriangles(vector<int>& arr) {
    int n = arr.size();
    int count = 0;

    // Sort the array in descending order
    sort(arr.begin(), arr.end(), greater<>());

    for (int i = 0; i < n - 2; i++) {
        int l = i + 1, r = n - 1;

        // Two-pointer technique to count valid triangles
        while (l < r) {
            if (arr[i] < arr[l] + arr[r]) {
                count += (r - l); // Count all pairs between l and r
                l++;
            } else {
                r--; // Decrease r if condition is not met
            }
        }
    }

    return count;
}

int main() {
    vector<int> arr = {6, 4, 9, 7, 8};
    cout << "Number of triangles: " << countTriangles(arr) << endl;
    return 0;
}
