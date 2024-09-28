#include<iostream>
using namespace std;
int main(){
    int m;
    cout<<"Enter first matrix rows: ";
    cin>>m;
    int n;
    cout<<"Enter first matrix column: ";
    cin>>n;
    int arr[m][n];
    int a;
    cout<<"Enter second matrix rows: ";
    cin>>a;
    int b;
    cout<<"Enter second matrix column: ";
    cin>>b;
    int brr[a][b];
    if(n==a){
        cout<<"Enter elements of first matrix:";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
        cout<<"Enter elements of second matrix:";
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>brr[i][j];
        }
    }
   int res[m][b];
  for(int i=0;i<m;i++){
    for(int j=0;j<b;j++){
          res[i][j]=0;
        for(int k=0;k<n;k++){
            res[i][j]=res[i][j]+arr[i][k]*brr[k][j];
        }
        cout<<res[i][j]<<" ";
    }
    cout<<endl;
  }
    }
    else{
        cout<<"Matrix multiplication not possible";
    }
    return 0;
}