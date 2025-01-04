
#include <iostream>
#include <vector>
using namespace std;

int countTriplets(vector<int> &arr, int target) {
    int n = arr.size(), cnt = 0;
    for (int i = 0; i < n - 2; i++) {
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum == target) {
                cnt++;
                int new_j = j + 1;
                while (new_j < k && arr[new_j - 1] == arr[new_j]) {
                    cnt++;
                    new_j++;
                }
                k--;
            }
            else if (sum < target) j++;
            else k--;
        }
    }
    return cnt;
}

int main() {
    // Example test case
    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 6;

    cout << "Number of triplets: " << countTriplets(arr, target) << endl;

    return 0;
}
