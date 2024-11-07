#include<iostream>
using namespace std;
int main()
{
    int a=10;
    cout<<&a<<endl;
    int *ptr=&a;
    cout<<ptr<<endl;
    cout<<sizeof(ptr)<<endl; // constant depend on system
    float m=2.6;
    float *ptr1=&m;
    cout<<ptr1<<endl;
    cout<<sizeof(ptr)<<endl;
return 0;
}


// In VS Code, you are likely using g++ (via MinGW or some other toolchain). Check if you are using the correct toolchain for 64-bit compilation.

// If you're using MinGW, you should use MinGW-w64, which supports 64-bit compilation. If you are using the 32-bit version of MinGW, it will compile as 32-bit, leading to 4-byte pointers.


// The size of a pointer in C++ depends on the system architecture (32-bit or 64-bit) rather than on the amount of RAM or ROM in your system. Specifically:

// On a 32-bit system, a pointer is typically 4 bytes (32 bits).
// On a 64-bit system, a pointer is typically 8 bytes (64 bits).
// The amount of RAM (e.g., 8 GB) or storage (e.g., 512 GB SSD) doesn't directly affect the size of a pointer. However, since modern laptops generally use 64-bit architecture, the pointer size is likely 8 bytes.