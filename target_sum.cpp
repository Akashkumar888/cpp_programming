
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countPairs(vector<int> &arr, int target) {
    int count = 0;
    unordered_map<int, int> mp;
    for (int &num : arr) {
        int remain = target - num;
        if (mp.find(remain) != mp.end()) count += mp[remain];
        mp[num]++;
    }
    return count;
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

    int result = countPairs(arr, target);
    cout << "The number of pairs with the given sum is: " << result << endl;

    return 0;
}
