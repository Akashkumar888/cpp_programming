#include <bits/stdc++.h>
using namespace std;
int main() {
char s[20];
cout<<"enter your string: ";
cin>>s;
cout<<"enter the new string or character to be pushed: ";
char t[20];
cin>>t;
strcat(s,t);
cout<<"The new string obtained is: "<<s;
}