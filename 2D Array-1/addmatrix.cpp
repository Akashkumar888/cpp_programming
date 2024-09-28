#include<iostream>
using namespace std;
int main(){
    int a[3][2]={1,2,3,4,5,6};
    int b[3][2]={7,8,9,10,11,12};
    int res[3][3];
   for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
         b[i][j]=b[i][j]+a[i][j];
         cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }

    // for(int i=0;i<3;i++){
    //     for(int j=0;j<2;j++){
    //         res[i][j]=a[i][j]+b[i][j];
    //     cout<<res[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int i=0;i<3;i++){
    //     for(int j=0;j<2;j++){
    //        cout<<res[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}