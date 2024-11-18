
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the second smallest element
int getSecondSmallest(vector<int> &arr) {
    int fs = INT_MAX; // First smallest
    int ss = INT_MAX; // Second smallest
    int n = arr.size();

    for (int &num : arr) {
        if (num < fs) {
            ss = fs;  // Update second smallest
            fs = num; // Update first smallest
        }
        else if (num > fs && num < ss) {
            ss = num; // Update second smallest
        }
    }

    return ss == INT_MAX ? -1 : ss;
}

// Function to find the second largest element
int getSecondLargest(vector<int> &arr) {
    int fl = INT_MIN; // First largest
    int sl = INT_MIN; // Second largest
    int n = arr.size();

    for (int &num : arr) {
        if (num > fl) {
            sl = fl;  // Update second largest
            fl = num; // Update first largest
        }
        else if (num < fl && num > sl) {
            sl = num; // Update second largest
        }
    }

    return sl == INT_MIN ? -1 : sl;
}

int main() {
    vector<int> arr = {12, 13, 1, 10, 34, 1};

    // Finding the second smallest element
    int secondSmallest = getSecondSmallest(arr);
    if (secondSmallest != -1)
        cout << "Second smallest element is: " << secondSmallest << endl;
    else
        cout << "There is no second smallest element" << endl;

    // Finding the second largest element
    int secondLargest = getSecondLargest(arr);
    if (secondLargest != -1)
        cout << "Second largest element is: " << secondLargest << endl;
    else
        cout << "There is no second largest element" << endl;

    return 0;
}

