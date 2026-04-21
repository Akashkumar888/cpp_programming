
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

A 
A B 
A B C 




// 3. Character Pyramid
#include<bits/stdc++.h>
using namespace std;

void charPyramid(int n) {
    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n-i-1; j++) cout << " ";

        char ch = 'A';
        for(int j = 0; j <= i; j++) {
            cout << ch++;
        }

        ch -= 2;
        for(int j = 0; j < i; j++) {
            cout << ch--;
        }

        cout << endl;
    }
}

int main(){
    int n; 
    cout<<"Enter n: ";
    cin >> n;
    charPyramid(n);
}

    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA

