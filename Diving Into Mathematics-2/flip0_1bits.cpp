#include<iostream>
using namespace std;
int poweroftwo(int n){
    int temp=n;
    n = (n | (n>>1));
    n = (n | (n>>2));
    n = (n | (n>>4));
    n = (n | (n>>8));
    n = (n | (n>>16));
 return (temp^n);
}
int main(){
    int n;
    cin>>n;
    cout<<poweroftwo(n);
    return 0;
}