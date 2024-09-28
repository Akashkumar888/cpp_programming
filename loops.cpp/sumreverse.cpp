#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number:";
    cin>>n;
    int a=n;
    int rem=0;
    int rev=0;
    while(n>0){
      rem=n%10;
        rev=rev*10+rem;
        n/=10;
    }
   cout<<rev + a;
    return 0;
}