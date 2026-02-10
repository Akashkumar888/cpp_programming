
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20;

    a = a + b;
    b = a - b;
    a = a - b;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}


// 📌 Advantages
// ✔ Simple logic
// ✔ No extra variable

// 📌 Disadvantages
// ❌ Overflow risk if a + b exceeds integer limit

#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}

// 📌 Advantages
// ✔ No overflow
// ✔ No extra memory
// ✔ Fast (bitwise operation)

// 📌 Disadvantages
// ❌ Less readable
// ❌ If a and b refer to same memory location → result becomes 0


// 1️⃣ Call by Value (❌ Original values NOT swapped)
// 📌 Explanation
// Copies of variables are passed
// Changes affect only local copies
// Original variables remain unchanged



#include <iostream>
using namespace std;

void swapValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;

    swapValue(x, y);

    cout << "x = " << x << endl;  // 10
    cout << "y = " << y << endl;  // 20
    return 0;
}


// 2️⃣ Call by Reference using & (C++ Reference Variable) ✅
// 📌 Explanation
// References refer to original variables
// Changes reflect in caller
// Most common C++ method


#include <iostream>
using namespace std;

void swapRef(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;

    swapRef(x, y);

    cout << "x = " << x << endl;  // 20
    cout << "y = " << y << endl;  // 10
    return 0;
}


// 3️⃣ Call by Reference using Pointers (*) ✅
// 📌 Explanation
// Addresses are passed
// Dereferencing changes original values
// Works in both C and C++


#include <iostream>
using namespace std;

void swapPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;

    swapPointer(&x, &y);

    cout << "x = " << x << endl;  // 20
    cout << "y = " << y << endl;  // 10
    return 0;
}


// 4️⃣ Using std::swap() (Call by Reference Internally) ⭐
// 📌 Explanation
// Defined in <algorithm>
// Uses references internally
// Best for real-world coding


#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int x = 10, y = 20;

    swap(x, y);

    cout << "x = " << x << endl;  // 20
    cout << "y = " << y << endl;  // 10
    return 0;
}
