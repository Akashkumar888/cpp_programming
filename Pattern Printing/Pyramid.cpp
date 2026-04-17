
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;

    int totalRows = 2 * n - 1;

    for (int i = 1; i <= totalRows; i++) {
        int row = (i <= n) ? i : totalRows - i + 1;

        // Left part
        for (int j = 1; j <= row; j++) {
            if (j == 1 || j == row) cout << "1 ";
            else cout << "0 ";
        }

        // Spaces (FIXED)
        int spaces = 2 * (n - row);
        for (int j = 1; j <= spaces; j++) {
            cout << "  ";
        }

        // Right part
        if (row == 1) {
            cout << "1";  // ensure first & last row prints 1 on right side
        } else {
            for (int j = 1; j <= row; j++) {
                if (j == 1 || j == row) cout << "1 ";
                else cout << "0 ";
            }
        }

        cout << endl;
    }

    return 0;
}

// 1                 1
// 1 1             1 1 
// 1 0 1         1 0 1 
// 1 0 0 1     1 0 0 1 
// 1 0 0 0 1 1 0 0 0 1 
// 1 0 0 1     1 0 0 1 
// 1 0 1         1 0 1 
// 1 1             1 1 
// 1                 1


