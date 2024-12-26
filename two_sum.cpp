
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool twoSum(vector<int>& arr, int target) {
    unordered_map<int, int> mp;
    for (int &num : arr) {
        int remain = target - num;
        if (mp.find(remain) != mp.end()) return true;
        mp[num]++;
    }
    return false;
}

int main() {
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target sum: ";
    cin >> target;

    if (twoSum(arr, target)) {
        cout << "Yes, there exists a pair with the given sum." << endl;
    } else {
        cout << "No, no such pair exists." << endl;
    }

    return 0;
}

