#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    int m=n-1;
    for(int a=1;a<=2*m+1;a++){
        cout<<"*";
    }
    cout<<endl;
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j++){
            cout<<"*";
        }
        for(int k=1;k<=2*i-1;k++){
            cout<<" ";
        }
        for(int l=i;l<=m;l++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}