#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    int n=str.size();
    cout<<str.substr(n/2);
    return 0;
}