
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



#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 3;
    for(int i=1;i<=n;i++){
    char ch='A';
    for(int j=1;j<=i;j++){
        cout<<ch++<<" ";
    }
    cout<<endl;
}
    return 0;
}




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

