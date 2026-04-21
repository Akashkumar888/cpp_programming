

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 3;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

1 
1 2 
1 2 3 


// Reverse version
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 3;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n-i+1; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

1 2 3 
1 2 
1 


// Same number triangle
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 3;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
1 
2 2 
3 3 3 

// Continuous numbers
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 3;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
           if(i!=n) cout << i+j-1 << " ";
           else cout << i+j << " ";
        }
        cout << endl;
    }
    return 0;
}

1 
2 3 
4 5 6 


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 3;
    int num = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
    return 0;
}

1 
2 3 
4 5 6 


// Reverse Number Triangle
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 3;
    for(int i=1;i<=n;i++){
    for(int j=i;j>=1;j--) cout<<j<<" ";
    cout<<endl;
}
    return 0;
}

1 
2 1 
3 2 1 


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;

    for(int i = 1; i <= n; i++) {

        // spaces
        for(int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        // numbers
        for(int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }
    return 0;
}

    1 
   1 2 
  1 2 3 
 1 2 3 4 
1 2 3 4 5 


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;

    for(int i = 1; i <= n; i++) {

        // spaces
        for(int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        // numbers
        for(int j = 1; j <= i; j++) {
            cout << i << " ";
        }

        cout << endl;
    }
    return 0;
}

    1 
   2 2 
  3 3 3 
 4 4 4 4 
5 5 5 5 5 


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    int num=1;
    for(int i = 1; i <= n; i++) {

        // spaces
        for(int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        // numbers
        for(int j = 1; j <= i; j++) {
            cout << num << " ";
            num++;
        }

        cout << endl;
    }
    return 0;
}

    1 
   2 3 
  4 5 6 
 7 8 9 10 
11 12 13 14 15 


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;

    for(int i = 1; i <= n; i++) {
         
         // spaces
        for(int j = 1; j <= i; j++) {
            cout << " ";
        }
        
         // numbers
        for(int j = 1; j <= n - i + 1; j++) {
            cout << j << " ";
        }
        
        cout << endl;
    }
    return 0;
}

 1 2 3 4 5 
  1 2 3 4 
   1 2 3 
    1 2 
     1 



#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;

    for(int i = 1; i <= n; i++) {
         
         // spaces
        for(int j = 1; j <= i; j++) {
            cout << " ";
        }
        
         // numbers
        for(int j = 1; j <= n - i + 1; j++) {
            cout << i << " ";
        }
        
        cout << endl;
    }
    return 0;
}

 1 1 1 1 1 
  2 2 2 2 
   3 3 3 
    4 4 
     5 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;

    for(int i = 1; i <= n; i++) {
         
         // spaces
        for(int j = 1; j <= i; j++) {
            cout << " ";
        }
        
         // numbers
        for(int j = 1; j <= n - i + 1; j++) {
            cout << n - i +1 << " ";
        }
        
        cout << endl;
    }
    return 0;
}

 5 5 5 5 5 
  4 4 4 4 
   3 3 3 
    2 2 
     1 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    int num=1;
    for(int i = 1; i <= n; i++) {
         
         // spaces
        for(int j = 1; j <= i; j++) {
            cout << " ";
        }
        
         // numbers
        for(int j = 1; j <= n - i + 1; j++) {
            cout << num << " ";
            num++;
        }
        
        cout << endl;
    }
    return 0;
}

 1 2 3 4 5 
  6 7 8 9 
   10 11 12 
    13 14 
     15 

// Number Pyramid (VERY COMMON)
#include <bits/stdc++.h>
using namespace std;

void numberPyramid(int n) {
    for(int i = 1; i <= n; i++) {

        for(int j = 1; j <= n-i; j++) cout << " ";

        for(int j = 1; j <= i; j++) cout << j;
        
        for(int j = i-1; j >= 1; j--) cout << j;

        cout << endl;
    }
}

int main(){
    int n; 
    cout<<"Enter n: ";
    cin >> n;
    numberPyramid(n);
}

    1
   121
  12321
 1234321
123454321


// 4. Floyd’s Triangle
#include <bits/stdc++.h>
using namespace std;

void floyd(int n) {
    int num = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << num++ << " ";
        }
        cout << endl;
    }
}

int main(){
    int n; 
    cout<<"Enter n: ";
    cin >> n;
    floyd(n);
}

// 5. Pascal Triangle (⭐ TCS loves this)

#include <bits/stdc++.h>
using namespace std;

void pascal(int n) {
    for(int i = 0; i < n; i++) {
        int val = 1;

        for(int j = 0; j < n-i; j++) cout << " ";

        for(int j = 0; j <= i; j++) {
            cout << val << " ";
            val = val * (i - j) / (j + 1);
        }

        cout << endl;
    }
}

int main(){
    int n; 
    cout<<"Enter n: ";
    cin >> n;
    pascal(n);
}

     1 
    1 1 
   1 2 1 
  1 3 3 1 
 1 4 6 4 1 



// 🔥 4. Diamond with Numbers
#include<bits/stdc++.h>
using namespace std;

void numberDiamond(int n) {

    // Upper part
    for(int i = 1; i <= n; i++) {

        // spaces
        for(int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        // increasing
        for(int j = 1; j <= i; j++) {
            cout << j;
        }

        // decreasing
        for(int j = i - 1; j >= 1; j--) {
            cout << j;
        }

        cout << endl;
    }

    // Lower part
    for(int i = n - 1; i >= 1; i--) {

        // spaces
        for(int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        // increasing
        for(int j = 1; j <= i; j++) {
            cout << j;
        }

        // decreasing
        for(int j = i - 1; j >= 1; j--) {
            cout << j;
        }

        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    numberDiamond(n);

    return 0;
}

    1
   121
  12321
 1234321
123454321
 1234321
  12321
   121
    1



// 🔥 6. Palindrome Triangle (VERY IMPORTANT)
#include<bits/stdc++.h>
using namespace std;

void palindromeTriangle(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << i;
        }
        cout << endl;
    }
}
int main(){
    int n; 
    cout<<"Enter n: ";
    cin >> n;
    palindromeTriangle(n);
}

1
22
333
4444
55555





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

    1 
   2 2 
  3 3 3 
 4 4 4 4 
5 5 5 5 5 
 4 4 4 4 
  3 3 3 
   2 2 
    1 



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


    1 
   2 2 
  3   3 
 4     4 
5       5 
 4     4 
  3   3 
   2 2 
    1 



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

1
1*3
1*3*5
1*3*5*7
1*3*5*7*9


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

