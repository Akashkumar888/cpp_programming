#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"a = ";
    cin>>a;
    cout<<"b = ";
    cin>>b;
    cout<<"c = ";
    cin>>c;
    int max=(a>b && a>c) ?a:(b>c?b:c);
    cout<<"Maximum ="<<max;
}