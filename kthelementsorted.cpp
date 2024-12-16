
#include <iostream>
#include <vector>
using namespace std;

int kthElement(vector<int>& a, vector<int>& b, int k) {
    int m = a.size(), n = b.size();
    int i = 0, j = 0, cnt = 0, ans;

    while (i < m && j < n) {
        if (a[i] <= b[j]) {
            ans = a[i++];
        } else {
            ans = b[j++];
        }
        cnt++;
        if (cnt == k) return ans;
    }
    while (i < m) {
        ans = a[i++];
        cnt++;
        if (cnt == k) return ans;
    }
    while (j < n) {
        ans = b[j++];
        cnt++;
        if (cnt == k) return ans;
    }
    return -1;
}

int main() {
    int m, n, k;
    cout << "Enter the size of the first array: ";
    cin >> m;
    vector<int> a(m);
    cout << "Enter elements of the first sorted array: ";
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    cout << "Enter the size of the second array: ";
    cin >> n;
    vector<int> b(n);
    cout << "Enter elements of the second sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    int result = kthElement(a, b, k);
    cout << "The " << k << "-th element is: " << result << endl;

    return 0;
}
