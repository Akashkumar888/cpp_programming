#include<iostream>
using namespace std;
int maxthree(int a,int b,int c){
    if(a>b && a>c)   return a; // ek bar ek hi return chalega
    else if(b>a && b>c)  return b;
    else  return c;
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
  cout<<"maximum of three: "<< maxthree(a,b,c);
    return 0;
}