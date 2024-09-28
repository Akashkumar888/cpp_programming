#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number :"<<endl;
    cin>>n;
    if(n%5==0 || n%3==0){
        if(n%15!=0){
            cout<<"Number is divisible by 5 or 3 but not 15"<<endl;
        }
        else{
            cout<<"Not matching"<<endl;
        }
    }
    else{
        cout<<"Not matching condtion"<<endl;
    }
    return 0;
}