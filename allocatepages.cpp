
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Function to check if the allocation is valid
bool valid(vector<int>& arr, int mid, int k) {
    int n = arr.size();
    int sum = 0, cnt = 1; // Number of students required
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum > mid) {
            sum = arr[i]; // Start a new student allocation
            cnt++;
            if(cnt>k)return false;
        }
    }
    return true;
}

// Function to find the minimum number of pages
int findPages(vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return -1; // Not enough books for the students

    int sum = 0, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        maxi = max(maxi, arr[i]);
    }

    int l = maxi, r = sum, ans = sum;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (valid(arr, mid, k)) {
            ans = mid;  // Try for a smaller maximum
            r = mid - 1;
        } else {
            l = mid + 1; // Increase the maximum allowed sum
        }
    }
    return ans;
}

// Main function
int main() {
    int n, k;
    cout << "Enter number of books and students: ";
    cin >> n >> k;
    vector<int> arr(n);
    cout << "Enter pages in each book: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int result = findPages(arr, k);
    if (result == -1)
        cout << "Not enough books for students!" << endl;
    else
        cout << "Minimum number of pages: " << result << endl;

    return 0;
}
