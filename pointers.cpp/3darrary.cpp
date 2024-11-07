#include<iostream>
using namespace std;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;  // Dimensions of the 3D array

    // Dynamically allocate memory for the 3D array
    int ***ptr = new int**[x];
    for(int i = 0; i < x; i++) {
        ptr[i] = new int*[y];
        for(int j = 0; j < y; j++) {
            ptr[i][j] = new int[z];
        }
    }

    // Input values into the 3D array
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            for(int k = 0; k < z; k++) {
                cin >> ptr[i][j][k];
            }
        }
    }

    // Output the 3D array
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            for(int k = 0; k < z; k++) {
                cout << ptr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Free the dynamically allocated memory
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            delete[] ptr[i][j];
        }
        delete[] ptr[i];
    }
    delete[] ptr;

    return 0;
}
