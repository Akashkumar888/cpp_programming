#include<iostream>
using namespace std;
int fib(int n){
    if(n==1 || n==2) return 1;
    int ans1=fib(n-1); // recursive first call
    int ans2=fib(n-2); //recursive second call 
    return ans1 +ans2;
}
int main(){
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}