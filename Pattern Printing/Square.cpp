
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


