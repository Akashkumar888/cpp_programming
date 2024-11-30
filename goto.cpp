
#include <iostream>
using namespace std;

int main() {
    int num = 1;

start:  // Label
    cout << "Number: " << num << endl;
    num++;

    if (num <= 5) {
        goto start;  // Jump back to the "start" label
    }

    cout << "End of program." << endl;

    return 0;
}

