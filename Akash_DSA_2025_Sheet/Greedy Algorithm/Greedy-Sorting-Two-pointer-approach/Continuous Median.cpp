
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int user_logic(int n, const vector<int>& arr) {
    vector<int> a = arr;        // make a copy since arr is const
    sort(a.begin(), a.end());

    long long sum = 0;          // prevent overflow
    int mid = n / 2;

    // Add elements from mid to end
    for (int i = mid; i < n; ++i) {
        sum += a[i];
    }

    // Add symmetric averages
    int left, right;

    if (n % 2 == 0) {
        left = mid - 1;
        right = mid;
    } else {
        left = mid - 1;
        right = mid + 1;
    }

    while (left >= 0 && right < n) {
        sum += (a[left] + a[right]) / 2;   // integer division
        left--;
        right++;
    }

    return (int)sum;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    int result = user_logic(n, arr);
    std::cout << result << std::endl;
    return 0;
}