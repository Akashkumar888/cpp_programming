#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    //  cin>>s; // only if the given string has no space
    getline(cin,s);
    cout<<s;
    return 0;
}