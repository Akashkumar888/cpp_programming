#include<iostream>
using namespace std;
int main(){
    int a[3][2]={1,2,3,4,5,6};
   for(int i=0;i<3;i++){
       for(int j=0;j<2;j++){
        cout<<a[i][j]<<" ";
       }
       cout<<endl;
   }
   
cout<<endl;
 for(int j=0;j<2;j++){
     for(int i=0;i<3;i++){
        cout<<a[i][j]<<" ";
       }
       cout<<endl;
   }
   
// cout<<endl;

// for(int i=0;i<2;i++){
//        for(int j=0;j<3;j++){
//         cout<<a[j][i]<<" ";
//        }
//        cout<<endl;
//    }

    return 0;
}