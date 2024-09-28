#include<iostream>
using namespace std;
int setbits(int n){
    return __builtin_popcount(n);
}
int main(){
    int n;
    cin>>n;
    cout<<setbits(n);
    return 0;
}