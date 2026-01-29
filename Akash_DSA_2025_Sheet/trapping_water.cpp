
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxWater(vector<int> &arr) {
    int n = arr.size();

    // Find the index of the maximum height bar
    int maxIdx = -1;
    int maxHeight = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxHeight) {
            maxHeight = arr[i];
            maxIdx = i;
        }
    }

    // Calculate water trapped on the left side
    int left = 0, leftHeight = 0, water = 0;
    while (left < maxIdx) {
        leftHeight = max(leftHeight, arr[left]);
        water += (leftHeight - arr[left]);
        left++;
    }

    // Calculate water trapped on the right side
    int right = n - 1, rightHeight = 0;
    while (right > maxIdx) {
        rightHeight = max(rightHeight, arr[right]);
        water += (rightHeight - arr[right]);
        right--;
    }

    return water;
}

int main() {
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Total water trapped: " << maxWater(heights) << endl;
    return 0;
}
