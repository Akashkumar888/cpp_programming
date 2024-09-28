#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    int m=n-1;
    int nsp=1;
    for(int b=1;b<=2*m+1;b++){
        cout<<b<<" ";
    }
    cout<<endl;
    for(int i=1;i<=m;i++){
        int a=1;
        for(int j=1;j<=m+1-i;j++){
            cout<<a<<" ";
            a++;
        }
        for(int k=1;k<=nsp;k++){
            cout<<"  ";
            a++;
        }
        nsp+=2;
        for(int l=1;l<=m+1-i;l++){
            cout<<a<<" ";
            a++;
        }
        cout<<endl;
    }
    return 0;
}