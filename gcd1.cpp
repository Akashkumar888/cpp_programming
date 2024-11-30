#include <iostream>
using namespace std;

int gcd(int x, int y) {
    x = abs(x);
    y = abs(y);
    if (x == 0) return y;
    if (y == 0) return x;
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

int main() {
    cout << gcd(2, 4) << endl;    // Output: 2
    cout << gcd(12, 15) << endl; // Output: 3
    cout << gcd(0, 5) << endl;   // Output: 5
    cout << gcd(-9, 3) << endl;  // Output: 3
    return 0;
}
