#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of series :";
    cin>>n;
    int a;
    cout<<"Enter the first term :";
    cin>>a;
    for(int i=1;i<=n;i++){
        cout<<a<<" ";
        a=a*2;
    }
    return 0;
}