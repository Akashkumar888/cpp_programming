
#include <iostream>
#include <cmath>
using namespace std;

double findSquareRoot(int n) {
    return sqrt(n);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Square root of " << n << " is: " << findSquareRoot(n) << endl;

    return 0;
}
