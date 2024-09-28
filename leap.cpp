#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the year :";
    cin>>n;
    if((n%4==0 && n%100!=0) || (n%400==0)){
       
        cout<<"Year is leap year :"<<n<<endl;
    }
    else{
        cout<<"Year is not leap year :"<<n<<endl;
    }
    return 0;
}