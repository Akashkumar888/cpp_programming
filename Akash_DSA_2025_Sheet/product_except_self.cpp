
#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n);
    ans[0] = 1;
    
    // Left product
    for (int i = 1; i < n; i++) {
        ans[i] = ans[i - 1] * arr[i - 1];
    }
    
    // Right product
    int prod = 1;
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = ans[i] * prod;
        prod *= arr[i];
    }
    
    return ans;
}

int main() {
    // Input array
    vector<int> arr = {1, 2, 3, 4};
    
    // Get the product array
    vector<int> result = productExceptSelf(arr);
    
    // Output the result
    cout << "Product of Array Except Self: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}

