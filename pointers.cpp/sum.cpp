#include<iostream>
using namespace std;
int sum(int *m,int *n){
    return *m+*n;
}
int main(){
int a,b;
cout<<"Enter a:";
cin>>a;
cout<<"Enter b:";
cin>>b;
cout<<sum(&a,&b);
    return 0;
}