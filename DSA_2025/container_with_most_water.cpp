
#include <iostream>
#include <vector>
using namespace std;

int maxWater(vector<int> &arr) {
    int n = arr.size();
    int water = 0;
    int i = 0, j = n - 1;

    while (i < j) {
        // Calculate area and update maximum water
        int height = min(arr[i], arr[j]);
        int area = (j - i) * height;
        water = max(area, water);

        // Move the pointer pointing to the smaller height
        if (arr[i] < arr[j])
            i++;
        else
            j--;
    }
    return water;
}

int main() {
    vector<int> arr = {1, 8, 6, 2, 5, 4, 8, 3, 7}; // Example input
    cout << "Maximum water that can be stored: " << maxWater(arr) << endl;
    return 0;
}
