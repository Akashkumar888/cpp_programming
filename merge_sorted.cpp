
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to merge two sorted arrays without extra space
void mergeArrays(vector<int>& a, vector<int>& b) {
    int m = a.size();
    int n = b.size();
    int i = m - 1, j = 0;

    // Swap elements to ensure they are in correct positions
    while (i >= 0 && j < n) {
        if (a[i] > b[j]) {
            swap(a[i--], b[j++]);
        } else {
            j++;
        }
    }

    // Sort both arrays to finalize the order
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

int main() {
    // Input size of both arrays
    int m, n;
    cout << "Enter size of first array: ";
    cin >> m;
    cout << "Enter size of second array: ";
    cin >> n;

    // Input elements of first array
    vector<int> a(m);
    cout << "Enter elements of first array (sorted): ";
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    // Input elements of second array
    vector<int> b(n);
    cout << "Enter elements of second array (sorted): ";
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // Call the merge function
    mergeArrays(a, b);

    // Print the merged arrays
    cout << "First array after merging: ";
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Second array after merging: ";
    for (int x : b) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
