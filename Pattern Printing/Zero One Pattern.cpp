// Binary Triangle
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 3;

    for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
        cout<<(i+j)%2<<" ";
    }
    cout<<endl;
}
    return 0;
}
0 
1 0 
0 1 0 


//  2. 0-1 Triangle (VERY COMMON)
#include<bits/stdc++.h>
using namespace std;

void zeroOneTriangle(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            if((i + j) % 2 == 0) cout << "1 ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

int main(){
    int n; 
    cout<<"Enter n: ";
    cin >> n;
    zeroOneTriangle(n);
}

1 
0 1 
1 0 1 
0 1 0 1 
1 0 1 0 1 



// 1. Solid 0–1 Butterfly
#include<bits/stdc++.h>
using namespace std;

void solid01Butterfly(int n) {

    // Upper part
    for(int i = 1; i <= n; i++) {

        // left side
        for(int j = 1; j <= i; j++) {
            cout << (j % 2);
        }

        // spaces
        for(int j = 1; j <= 2*(n-i); j++) {
            cout << " ";
        }

        // right side (reverse pattern)
        for(int j = i; j >= 1; j--) {
            cout << (j % 2);
        }

        cout << endl;
    }

    // Lower part
    for(int i = n; i >= 1; i--) {

        for(int j = 1; j <= i; j++) {
            cout << (j % 2);
        }

        for(int j = 1; j <= 2*(n-i); j++) {
            cout << " ";
        }

        for(int j = i; j >= 1; j--) {
            cout << (j % 2);
        }

        cout << endl;
    }
}

int main(){
    int n; 
    cout<<"Enter n: ";
    cin >> n;
    solid01Butterfly(n);
}

1        1
10      01
101    101
1010  0101
1010110101
1010110101
1010  0101
101    101
10      01
1        1



// 🔥 2. Hollow 0–1 Butterfly ⭐

#include<bits/stdc++.h>
using namespace std;

void hollow01Butterfly(int n) {

    // Upper
    for(int i = 1; i <= n; i++) {

        // left side
        for(int j = 1; j <= i; j++) {
            if(j == 1 || j == i)
                cout << (j % 2);
            else
                cout << " ";
        }

        // spaces
        for(int j = 1; j <= 2*(n-i); j++) {
            cout << " ";
        }

        // right side
        for(int j = i; j >= 1; j--) {
            if(j == 1 || j == i)
                cout << (j % 2);
            else
                cout << " ";
        }

        cout << endl;
    }

    // Lower
    for(int i = n; i >= 1; i--) {

        for(int j = 1; j <= i; j++) {
            if(j == 1 || j == i)
                cout << (j % 2);
            else
                cout << " ";
        }

        for(int j = 1; j <= 2*(n-i); j++) {
            cout << " ";
        }

        for(int j = i; j >= 1; j--) {
            if(j == 1 || j == i)
                cout << (j % 2);
            else
                cout << " ";
        }

        cout << endl;
    }
}

int main(){
    int n; 
    cout<<"Enter n: ";
    cin >> n;
    hollow01Butterfly(n);
}

1        1
10      01
1 1    1 1
1  0  0  1
1   11   1
1   11   1
1  0  0  1
1 1    1 1
10      01
1        1



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

1                 1
1 1             1 1 
1 0 1         1 0 1 
1 0 0 1     1 0 0 1 
1 0 0 0 1 1 0 0 0 1 
1 0 0 1     1 0 0 1 
1 0 1         1 0 1 
1 1             1 1 
1                 1



#include <bits/stdc++.h>
using namespace std;
void diagonalZeroOne(int n){
for(int i = 1; i <= n; i++){
    for(int j = 1; j <= i; j++){
        if(j == i) cout << "1 ";
        else cout << "0 ";
    }
    cout << endl;
}
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
    diagonalZeroOne(n);
    return 0;
}


1 
0 1 
0 0 1 
0 0 0 1 
0 0 0 0 1 


// 🔥 4. Checkerboard Pattern
#include <bits/stdc++.h>
using namespace std;
void diagonalZeroOne(int n){
for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
        cout << ((i + j) % 2) << " ";
    }
    cout << endl;
}
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
    diagonalZeroOne(n);
    return 0;
}

0 1 0 1 0 
1 0 1 0 1 
0 1 0 1 0 
1 0 1 0 1 
0 1 0 1 0 


// 🔥 5. Pyramid 0–1 Pattern

#include <bits/stdc++.h>
using namespace std;
void diagonalZeroOne(int n){
for(int i = 1; i <= n; i++){

    for(int s = 1; s <= n-i; s++) cout << " ";

    for(int j = 1; j <= i; j++){
        cout << ((i + j) % 2) << " ";
    }

    cout << endl;
}
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
    diagonalZeroOne(n);
    return 0;
}

    0 
   1 0 
  0 1 0 
 1 0 1 0 
0 1 0 1 0 


// 🔥 Pattern Building Formula (VERY IMPORTANT)
// 👉 Any 0–1 pattern =
// value = (i + j) % 2   // checker
// value = j % 2         // column-based
// value = i % 2         // row-based
// value = boundary ? 1 : 0