#include<iostream>
#include <cmath>
#include <numeric>  // Include this to use the gcd function in C++17 and later
using namespace std;

int lcmoftwo(int a, int b) {
    return abs(a * b) / gcd(a, b);  // Use gcd from the <numeric> library
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << lcmoftwo(a, b) << endl;
}
