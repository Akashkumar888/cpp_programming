
#include <iostream>
#include <vector>
using namespace std;

// Helper function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

vector<int> findCompositeNumbers(int n) {
    vector<int> compositeNumbers;
    for (int i = 4; i <= n; i++) { // Start from 4 as composite numbers begin from 4
        if (!isPrime(i)) {
            compositeNumbers.push_back(i);
        }
    }
    return compositeNumbers;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    vector<int> compositeNumbers = findCompositeNumbers(n);
    cout << "Composite numbers up to " << n << " are: ";
    for (int num : compositeNumbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
