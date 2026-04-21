
// Simple Square

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    for(int i = 1; i <= n; i++) {
         // numbers
        for(int j = 1; j <= n ; j++) {
            cout << 1 << " ";
        }
        
        cout << endl;
    }
    return 0;
}


1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1

// Row-wise Same Number Square
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    for(int i = 1; i <= n; i++) {
         // numbers
        for(int j = 1; j <= n ; j++) {
            cout << i << " ";
        }
        
        cout << endl;
    }
    return 0;
}

1 1 1 1 1
2 2 2 2 2
3 3 3 3 3
4 4 4 4 4
5 5 5 5 5


// Column-wise Increasing Square
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    for(int i = 1; i <= n; i++) {
         // numbers
        for(int j = 1; j <= n ; j++) {
            cout << j << " ";
        }
        
        cout << endl;
    }
    return 0;
}

1 1 1 1 1
2 2 2 2 2
3 3 3 3 3
4 4 4 4 4
5 5 5 5 5


// Continuous Number Square
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    int num=1;
    for(int i = 1; i <= n; i++) {
         // numbers
        for(int j = 1; j <= n ; j++) {
            cout << num << " ";
            num++;
        }
        
        cout << endl;
    }
    return 0;
}


1  2  3  4  5
6  7  8  9  10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25

// Reverse Column Square
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    for(int i = 1; i <= n; i++) {
         // numbers
        for(int j = 1; j <= n ; j++) {
            cout << n - j + 1 << " ";
        }
        
        cout << endl;
    }
    return 0;
}

5 4 3 2 1
5 4 3 2 1
5 4 3 2 1
5 4 3 2 1
5 4 3 2 1



// Reverse Row Square
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    for(int i = 1; i <= n; i++) {
         // numbers
        for(int j = 1; j <= n ; j++) {
            cout << n  - i +  1 << " ";
        }
        
        cout << endl;
    }
    return 0;
}

5 5 5 5 5
4 4 4 4 4
3 3 3 3 3
2 2 2 2 2
1 1 1 1 1


// Border Square
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    for(int i = 1; i <= n; i++) {
         // numbers
        for(int j = 1; j <= n ; j++) {
         if(i==1 || i==n || j==1 || j==n)cout << "1 " ;
         else cout<<"  ";
        }
        cout << endl;
    }
    return 0;
}

1 1 1 1 1
1       1
1       1
1       1
1 1 1 1 1


// Diagonal Square
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
        if(i == j || i + j == n + 1)//diagonal rule i==j and i+j==n+1
            cout << "1 ";
        else
            cout << "  ";
    }
    cout << endl;
}
    return 0;
}


1       1
 1     1 
   1 1   
 1     1 
1       1

// 🔥 TCS Interview Tip
// They often ask:

// 👉 “What will be output of this code?”
// Example:
// cout << n - j + 1;
// 👉 You should instantly say:
// “Reverse column pattern”
