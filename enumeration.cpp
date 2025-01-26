
#include <iostream>
using namespace std;

int main() {
    int n = 1;

start:
    if (n <= 5) {
        cout << n << " ";
        n++;
        goto start; // Jump back to the label 'start'
    }
    return 0;
}
