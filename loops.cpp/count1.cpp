#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    for(int i=1;i<=10;i++){
    for(int j=i;j<=n;j=j+10){
        cout<<j<<"\t";
    }
    cout<<endl;
    }
    return 0;
}
// int main(){
//     for(int i=1;i<=100;i++){
//         cout<<i<<endl;
//     }
//     return 0;
// }