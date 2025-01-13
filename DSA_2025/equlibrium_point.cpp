
#include <iostream>
#include <vector>
using namespace std;

// Function to find the equilibrium index
int findEquilibrium(vector<int> &arr) {
    int n = arr.size();
    vector<int> presum(n); // To store prefix sum from right to left
    int sum = 0;

    // Calculate right prefix sum
    for (int i = n - 1; i >= 1; i--) {
        sum += arr[i];
        presum[i] = sum;
    }

    // Reset sum for left-side calculation
    sum = 0;
    for (int i = 0; i < n - 1; i++) {
        if (sum == presum[i + 1]) 
            return i; // Equilibrium index found
        sum += arr[i];
    }

    return -1; // No equilibrium index exists
}

int main() {
    // Input array
    vector<int> arr = {1, 3, 5, 2, 2};

    // Find and print the equilibrium index
    int index = findEquilibrium(arr);
    if (index != -1) {
        cout << "Equilibrium index is: " << index << endl;
    } else {
        cout << "No equilibrium index exists." << endl;
    }

    return 0;
}

