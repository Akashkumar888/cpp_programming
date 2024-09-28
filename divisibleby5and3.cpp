#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number :";
    cin>>n;
    if(n%3==0 && n%5==0){
        cout<<"Divisible by both 3 and 5"<<endl;
    }
    else{
        cout<<" Not Divisible by  3 and 5"<<endl;
    }
    return 0;
}