#include<iostream>
using namespace std;
int main(){
    int y=31;
    int x=23;
    cout<<__builtin_popcount(x^y);
    return 0;
}