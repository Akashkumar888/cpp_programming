#include<iostream>
#include<math.h>
using namespace std;
bool isprime(int n){
    if(n==1) return false;
     for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
     }
     return true;
}
int main(){
    int n;
    cin>>n;
     if(isprime(n))cout<<"prime number";
     else cout<<"not prime number";
    return 0;
}