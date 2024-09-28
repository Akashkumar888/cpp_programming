#include<iostream>
using namespace std;
int fact(int x){
   int f=1;
    for(int i=2;i<=x;i++){
      f=f*i;  
    }
    return f;
}
int combination(int n,int r){
    int ncr=fact(n)/(fact(r)*fact(n-r));
    return ncr;
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    for(int i=0;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<"  ";
        }
        for(int k=0;k<=i;k++){
        cout<<combination(i , k)<<"   ";
        }
        cout<<endl;
    }
    return 0;
}