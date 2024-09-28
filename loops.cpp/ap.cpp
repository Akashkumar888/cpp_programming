#include<iostream>
using namespace std;
// int main(){
//     int n;
//     cout<<"Enter the number :";
//     cin>>n;
//     for(int i=1;i<=2*n-1;i=i+2)
//     cout<<i<<"  ";
//     return 0;
// }

int main(){
    int n;
    cout<<"Enter the number of series:";
    cin>>n;
    int a;
    cout<<"Enter the first term :";
    cin>>a;
    for(int i=1;i<=n;i++){
    cout<<a<<"  ";
    a=a+3;
    }
    return 0;
}