#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=2;i<sqrt(n);i++){
        if(n%i==0) cout<<i<<" ";
    }
    for(int i=sqrt(n);i>=2;i--){
        if(n%i==0)cout<<(n/i)<<" ";     
    }
    return 0;
}