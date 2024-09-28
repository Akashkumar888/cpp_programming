#include<iostream>
#include <numeric>  // Ensure you're using C++17 or later
using namespace std;

int main() {
    int a = 12;
    int b = 15;
    
    // C++17 and above supports gcd from the <numeric> header
    int gcd_value = gcd(a, b);
    
    cout << "GCD of " << a << " and " << b << " is " << gcd_value << endl;
    
    return 0;
}
