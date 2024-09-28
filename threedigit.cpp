#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number :";
    cin>>n;
    if(n>=100 && n<=999){
        cout<<"Three digit number"<<endl;
    }
    else{
        cout<<"Not three digit number"<<endl;
    }
    return 0;
}