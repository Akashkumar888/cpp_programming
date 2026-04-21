#include <bits/stdc++.h>
using namespace std;

    void printDiamondUpperPart(int n) {

        // Upper part
        int space = n - 1;
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < space; j++) {
                cout << " ";
            }

            for(int j = 0; j <= i; j++) {
                cout << "* ";
            }

            space--;
            cout << endl;
        }
    }

int main() {
    int n;
    cout<<"Enter n: ";
    cin >> n;
    printDiamondUpperPart(n);

    return 0;
}

    * 
   * * 
  * * * 
 * * * * 
* * * * * 

#include <bits/stdc++.h>
using namespace std;

    void printDiamondLowerPart(int n) {

        // Upper part
        int space = 1;
        for(int i = n-1; i >=0; i--) {

            for(int j = 0; j < space; j++) {
                cout << " ";
            }

            for(int j = 0; j <= i; j++) {
                cout << "* ";
            }

            space++;
            cout << endl;
        }
    }

int main() {
    int n;
    cout<<"Enter n: ";
    cin >> n;
    printDiamondLowerPart(n);

    return 0;
}

 * * * * * 
  * * * * 
   * * * 
    * * 
     * 


#include <bits/stdc++.h>
using namespace std;

    void printDiamond(int n) {

        // Upper part
        int space = n - 1;
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < space; j++) {
                cout << " ";
            }

            for(int j = 0; j <= i; j++) {
                cout << "* ";
            }

            space--;
            cout << endl;
        }

        // Lower part (fix here)
        space = 1;
        for(int i = n - 2; i >= 0; i--) {

            for(int j = 0; j < space; j++) {
                cout << " ";
            }

            for(int j = 0; j <= i; j++) {
                cout << "* ";
            }

            space++;
            cout << endl;
        }
    }

int main() {
    int n;
    cout<<"Enter n: ";
    cin >> n;
    printDiamond(n);

    return 0;
}

   * 
  * * 
 * * * 
* * * * 
 * * * 
  * * 
   * 
   



   class Solution {
  public:
    void printDiamond(int n) {
        // code here
        // upper shape
        int space=n-1;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<space;j++){
                cout<<" ";
            }
            
            for(int j=0;j<=i;j++){
                cout<<"* ";
            }
            space--;
            cout<<endl;
        }
        // lower shape
        space=1;
        for(int i=n-1;i>=0;i--){
            
            for(int j=0;j<space;j++){
                cout<<" ";
            }
            for(int j=0;j<=i;j++){
                cout<<"* ";
            }
            space++;
            cout<<endl;
        }
    }
};


   * 
  * * 
 * * * 
* * * * 
* * * * 
 * * * 
  * * 
   * 
  

   
#include <bits/stdc++.h>
using namespace std;

void printHollowDiamond(int n) {

    // Upper part
    int space = n - 1;
    for(int i = 0; i < n; i++) {

        // spaces before stars
        for(int j = 0; j < space; j++) {
            cout << " ";
        }

        // hollow stars
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i) {
                cout << "* ";
            } 
            else {
                cout << "  ";
            }
        }

        space--;
        cout << endl;
    }

    // Lower part
    space = 1;
    for(int i = n - 2; i >= 0; i--) {

        for(int j = 0; j < space; j++) {
            cout << " ";
        }

        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i) {
                cout << "* ";
            } 
            else {
                cout << "  ";
            }
        }

        space++;
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    printHollowDiamond(n);

    return 0;
}


   * 
  * * 
 *   * 
*     * 
 *   * 
  * * 
   * 
  
//    🔥 Key Difference from Solid Pattern
// Solid	Hollow
// Always *	Only boundary *
// cout << "* "	condition check

// 🔹 Interview Tip 💡
// If asked:
// “How to convert solid → hollow?”
// Say:
// “Print star only at boundaries, otherwise print spaces.”



#include <bits/stdc++.h>
using namespace std;

void hollowSquare(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            if(i == 0 || i == n-1 || j == 0 || j == n-1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin >> n;
    hollowSquare(n);
}


* * * * * 
*       * 
*       * 
*       * 
* * * * * 



#include<bits/stdc++.h>
using namespace std;

void hollowTriangle(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {

            if(i == 0 || i == n-1 || j == 0 || j == i)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

int main(){
  int n;
    cout<<"Enter n: ";
    cin >> n;
    hollowTriangle(n);
}


* 
* * 
*   * 
*     * 
* * * * * 


#include<bits/stdc++.h>
using namespace std;

void pattern(int n) {
    for(int i = 0; i < n; i++) {

        // wider spaces
        for(int s = 0; s < 2*(n - i - 1); s++) {
            cout << " ";
        }

        for(int j = 0; j <= i; j++) {

            if(i == 0 || i == n-1 || j == 0 || j == i)
                cout << "* ";
            else
                cout << "  ";
        }

        cout << endl;
    }
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin >> n;
    pattern(n);
}

        * 
      * * 
    *   * 
  *     * 
* * * * * 



#include<bits/stdc++.h>
using namespace std;

void mirrorWaterTriangle(int n) {
    for(int i = n-1; i >= 0; i--) {

        for(int j = 0; j <= i; j++) {

            if(i == 0 || i == n-1 || j == 0 || j == i)
                cout << "* ";
            else
                cout << "  ";
        }

        cout << endl;
    }
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin >> n;
    mirrorWaterTriangle(n);
}

* * * * * 
*     * 
*   * 
* * 
* 


#include<bits/stdc++.h>
using namespace std;

void reversePattern(int n) {
    int space = 0;

    for(int i = n-1; i >= 0; i--) {

        for(int s = 0; s < space; s++) {
            cout << " ";
        }

        for(int j = 0; j <= i; j++) {

            if(i == 0 || i == n-1 || j == 0 || j == i)
                cout << "* ";
            else
                cout << "  ";
        }

        space += 2; // important
        cout << endl;
    }
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin >> n;
    reversePattern(n);
}

* * * * * 
  *     * 
    *   * 
      * * 
        * 



// ✅ Correct Code (Right-Aligned Hollow Triangle)
#include<bits/stdc++.h>
using namespace std;

void hollowRightTriangle(int n) {
    for(int i = 0; i < n; i++) {

        // spaces before stars
        for(int s = 0; s < n - i - 1; s++) {
            cout << " ";
        }

        // stars
        for(int j = 0; j <= i; j++) {

            if(i == 0 || i == n-1 || j == 0 || j == i)
                cout << "* ";
            else
                cout << "  ";
        }

        cout << endl;
    }
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;

    hollowRightTriangle(n);
}
    * 
   * * 
  *   * 
 *     * 
* * * * *



#include<bits/stdc++.h>
using namespace std;

void waterHollowTriangle(int n) {
    int space = 0;

    for(int i = n-1; i >= 0; i--) {

        for(int s = 0; s < space; s++) {
            cout << " ";
        }

        for(int j = 0; j <= i; j++) {

            if(i == 0 || i == n-1 || j == 0 || j == i)
                cout << "* ";
            else
                cout << "  ";
        }

        space++;
        cout << endl;
    }
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin >> n;
    waterHollowTriangle(n);
}

* * * * * 
 *     * 
  *   * 
   * * 
    * 





#include<bits/stdc++.h>
using namespace std;


void hollowPyramid(int n) {
    for(int i = 0; i < n; i++) {

        // spaces
        for(int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }

        for(int j = 0; j < 2*i + 1; j++) {

            if(i == 0 || i == n-1 || j == 0 || j == 2*i)
                cout << "*";
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
    hollowPyramid(n);
}


    *
   * *
  *   *
 *     *
*********

#include <bits/stdc++.h>
using namespace std;

void hollowInvertedPyramid(int n) {
    for(int i = n; i >= 1; i--) {

        for(int j = 0; j < n-i; j++) cout << " ";

        for(int j = 0; j < 2*i-1; j++) {
            if(i == n || i == 1 || j == 0 || j == 2*i-2)
                cout << "*";
            else
                cout << " ";
        }

        cout << endl;
    }
}

int main(){
    int n; 
    cout<<"Enter n:";
    cin >> n;
    hollowInvertedPyramid(n);
}


*********
 *     *
  *   *
   * *
    *



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

    *
   ***
  *****
 *******
*********


// 🔥 1. Butterfly Pattern (VERY IMPORTANT ⭐)
// Solid Butterfly

#include <bits/stdc++.h>
using namespace std;

void butterfly(int n) {
    // Upper
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) cout << "*";
        for(int j = 1; j <= 2*(n-i); j++) cout << " ";
        for(int j = 1; j <= i; j++) cout << "*";
        cout << endl;
    }

    // Lower
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= i; j++) cout << "*";
        for(int j = 1; j <= 2*(n-i); j++) cout << " ";
        for(int j = 1; j <= i; j++) cout << "*";
        cout << endl;
    }
}

int main(){
    int n; 
    cout<<"Enter n: ";
    cin >> n;
    butterfly(n);
}

*        *
**      **
***    ***
****  ****
**********
**********
****  ****
***    ***
**      **
*        *


// Hollow Butterfly (🔥 asked frequently)
#include <bits/stdc++.h>
using namespace std;

void hollowButterfly(int n) {
    for(int i = 1; i <= n; i++) {

        for(int j = 1; j <= i; j++) {
            if(j == 1 || j == i) cout << "*";
            else cout << " ";
        }

        for(int j = 1; j <= 2*(n-i); j++) cout << " ";

        for(int j = 1; j <= i; j++) {
            if(j == 1 || j == i) cout << "*";
            else cout << " ";
        }

        cout << endl;
    }

    for(int i = n; i >= 1; i--) {

        for(int j = 1; j <= i; j++) {
            if(j == 1 || j == i) cout << "*";
            else cout << " ";
        }

        for(int j = 1; j <= 2*(n-i); j++) cout << " ";

        for(int j = 1; j <= i; j++) {
            if(j == 1 || j == i) cout << "*";
            else cout << " ";
        }

        cout << endl;
    }
}

int main(){
    int n; 
    cout<<"Enter n: ";
    cin >> n;
    hollowButterfly(n);
}

*        *
**      **
* *    * *
*  *  *  *
*   **   *
*   **   *
*  *  *  *
* *    * *
**      **
*        *



// 1. Zig-Zag Pattern (VERY IMPORTANT ⭐)
#include<bits/stdc++.h>
using namespace std;

void zigzag(int n) {
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= n; j++) {
            if((i + j) % 4 == 0 || (i == 2 && j % 4 == 0))
                cout << "*";
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
    zigzag(n);
}

  *   *  
 * * * * 
*   *   *



//  6. Hollow Rectangle (variation)

#include <bits/stdc++.h>
using namespace std;

void hollowRectangle(int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 || i == n-1 || j == 0 || j == m-1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

int main(){
    int n,m; 
    cout<<"Enter n: ";
    cin >> n;
    cout<<"Enter m: ";
    cin>> m;
    hollowRectangle(n,m);
}

****
*  *
*  *
*  *
****


// 🔥 5. Hourglass Pattern ⭐
#include<bits/stdc++.h>
using namespace std;

void hourglass(int n) {
    // upper
    for(int i = n; i >= 1; i--) {
        for(int s = 0; s < n-i; s++) cout << " ";
        for(int j = 0; j < i; j++) cout << "*";
        cout << endl;
    }

    // lower
    for(int i = 2; i <= n; i++) {
        for(int s = 0; s < n-i; s++) cout << " ";
        for(int j = 0; j < i; j++) cout << "*";
        cout << endl;
    }
}

int main(){
    int n; 
    cout<<"Enter n: ";
    cin >> n;
    hourglass(n);
}


*****
 ****
  ***
   **
    *
   **
  ***
 ****
*****