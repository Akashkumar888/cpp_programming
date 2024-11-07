
#include <iostream>
using namespace std;

int main() {
    try {
        cout << "try block start here:" << endl;
        int x = 0;  // Assuming x isn't defined; simulate an error.
        cout << x << endl;
        cout << "try block ends here:" << endl;
    }
    catch (...) {  // Catching any exception
        cout << "I am inside catch block" << endl;
    }
    return 0;
}
