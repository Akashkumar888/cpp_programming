
#include <iostream>
#include <cmath> // for log10 and log2

using namespace std;

int countDigits(int n) {
    if (n == 0) return 1; // Special case for 0, which has 1 digit
    return floor(log10(n)) + 1;
}

int countBits(int n) {
    if (n == 0) return 1; // Special case for 0, which has 1 bit in binary
    return floor(log2(n)) + 1;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    // Number of digits
    int digits = countDigits(n);
    cout << "Number of digits in " << n << " is: " << digits << endl;
    
    // Number of bits
    int bits = countBits(n);
    cout << "Number of bits in " << n << " is: " << bits << endl;
    
    return 0;
}
