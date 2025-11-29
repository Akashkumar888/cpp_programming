
#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int &b = a; // reference to a
    // jaise hum function me value pass by references pass krte hai 

    cout << "a = " << a << endl;   // 5
    cout << "b = " << b << endl;   // 5

    b = 20; // changing b changes a

    cout << "a after change = " << a << endl; // 20
    cout << "b after change = " << b << endl; // 20
}
