#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    if(a>b){
        int rem=a%b;
        cout<<"remainder = "<<rem;
    }
    else{
        int rem=b%a;
        cout<<"remainder = "<<rem;
    }
}