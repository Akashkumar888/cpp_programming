#include <iostream>
#include <cmath>  // For log10, log2, floor, ceil

using namespace std;

int main() {
    // Original expressions
    double log10_value = log10(10); // base-10 logarithm of 10
    double log2_value = log2(10);   // base-2 logarithm of 10
    
    // Showing the result of the original expressions with +1
    cout << "log10(10) + 1: " << log10_value + 1 << endl;
    cout << "log2(10) + 1: " << log2_value + 1 << endl;
    
    // Using floor and ceil on the logarithmic values
    cout << "Floor of log10(10) + 1: " << floor(log10_value + 1) << endl;
    cout << "Ceil of log10(10) + 1: " << ceil(log10_value + 1) << endl;

    cout << "Floor of log2(10) + 1: " << floor(log2_value + 1) << endl;
    cout << "Ceil of log2(10) + 1: " << ceil(log2_value + 1) << endl;

    return 0;
}
