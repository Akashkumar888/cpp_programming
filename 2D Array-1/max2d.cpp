#include<iostream>
using namespace std;
int main(){
    int a[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
        }
    }
    int max=a[0][0];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
          if(max<a[i][j]){
            max=a[i][j];
          }
        }
    }
        cout<<max ;
    return 0;
}