
#include <iostream>
#include <vector>
using namespace std;

void rot(vector<int>& nums, int i, int j) {
    while (i < j) {
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
}

void rotateArr(vector<int>& arr, int d) {
    int n = arr.size();
    if (d >= n) d = d % n; // Handle cases where d >= n
    if (d == 0) return;    // No rotation needed if d is 0
    rot(arr, 0, d - 1);    // Reverse the first part
    rot(arr, d, n - 1);    // Reverse the second part
    rot(arr, 0, n - 1);    // Reverse the whole array
}

int main() {
    int n, d;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the number of rotations: ";
    cin >> d;

    rotateArr(arr, d);

    cout << "Array after " << d << " rotations: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
