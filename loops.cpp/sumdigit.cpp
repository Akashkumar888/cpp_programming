#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number:";
    cin>>n;
    int sum=0;
    int rem;
    while(n>0){
      rem=n%10;
        sum+=rem;
        n/=10;
    }
   cout<<sum;
    return 0;
}