#include<iostream>
using namespace std;
// int main(){
//     int n;
//     cout<<"Enter the number :";
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         if(i%2==0){
//             cout<<i<<endl;
//         }
//     }
//     return 0;
// }

int main(){
    int n;
    cout<<"Enter the number :";
    cin>>n;
    for(int i=2;i<=n;i=i+2){
            cout<<i<<endl;
    }
    return 0;
}