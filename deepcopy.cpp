#include <iostream>
using namespace std;

// Box Class
class box {
private:
    int length;
    int breadth;
    int height;

public:
    // Constructor
    box() {}

    // Function to set the dimensions
    void set_dimension(int len, int brea, int heig) {
        length = len;
        breadth = brea;
        height = heig;
    }

    // Function to show the dimensions
    void show_data() {
        cout << " Length = " << length
             << "\n Breadth = " << breadth
             << "\n Height = " << height
             << endl;
    }

    // Copy constructor for deep copy
    box(const box& sample) {
        length = sample.length;
        breadth = sample.breadth;
        height = sample.height;
    }
};

// Driver Code
int main() {
    // Object of class first
    box first;

    // Set the dimensions
    first.set_dimension(12, 14, 16);

    // Display the dimensions
    first.show_data();

    // Create a new object using the copy constructor
    box second = first;

    // Display the dimensions
    second.show_data();

    return 0;
}
