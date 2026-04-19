
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


// SOLID DIAMOND
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter n"<<endl;
    cin>>n;

    // Upper part
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n-i;k++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    // Lower part
    for(int i=n-1;i>=1;i--){
        for(int k=1;k<=n-i;k++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}

// HOLLOW DIAMOND
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter n"<<endl;
    cin>>n;

    // Upper
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n-i;k++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            if(j==1 || j==i){
                cout<<i;
            } else {
                cout<<" ";
            }
            cout<<" ";
        }
        cout<<endl;
    }

    // Lower
    for(int i=n-1;i>=1;i--){
        for(int k=1;k<=n-i;k++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            if(j==1 || j==i){
                cout<<i;
            } else {
                cout<<" ";
            }
            cout<<" ";
        }
        cout<<endl;
    }

    return 0;
}

// ODD NUMBER STAR PATTERN
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter n"<<endl;
    cin>>n;

    for(int i=1;i<=n;i++){
        int temp=1;
        for(int j=1;j<=i;j++){
            cout<<temp;
            if(i!=j) cout<<"*";
            temp+=2;
        }
        cout<<endl;
    }

    return 0;
}


// Equilateral Triangle (Centered Star Pyramid)
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n" << endl;
    cin >> n;

    for(int i = 1; i <= n; i++) {

        // spaces
        for(int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        // stars (odd numbers: 2*i - 1)
        for(int j = 1; j <= 2*i - 1; j++) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}

// Hollow Equilateral Triangle

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n" << endl;
    cin >> n;

    for(int i = 1; i <= n; i++) {

        for(int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        for(int j = 1; j <= 2*i - 1; j++) {
            if(j == 1 || j == 2*i - 1 || i == n)
                cout << "*";
            else
                cout << " ";
        }

        cout << endl;
    }

    return 0;
}