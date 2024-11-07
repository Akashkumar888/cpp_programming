#include <iostream>
using namespace std;

// Box Class
class box {
private:
    int length;
    int breadth;
    int height;
    int p;  // Instead of using a pointer, just use a regular integer

public:
    // Function to set the dimensions
    void set_dimensions(int length1, int breadth1, int height1, int x) {
        length = length1;
        breadth = breadth1;
        height = height1;
        p = x;  // Set the value of p directly
    }

    // Function to display the dimensions of the Box object
    void show_data() {
        cout << " Length = " << length
             << "\n Breadth = " << breadth
             << "\n Height = " << height
             << "\n Value of p = " << p
             << endl;
    }
};

int main() {
    // Object of class Box
    box B1, B3;

    // Set dimensions of Box B1
    B1.set_dimensions(14, 12, 16, 100);
    B1.show_data();

    // When copying the data of the object at the time of initialization
    // Copy is made through the default copy constructor (shallow copy)
    box B2 = B1;
    B2.show_data();

    // When copying the data of the object after initialization
    // Copy is done through the default assignment operator (shallow copy)
    B3 = B1;
    B3.show_data();

    return 0;
}
