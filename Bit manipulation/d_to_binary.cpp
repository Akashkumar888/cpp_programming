#include<iostream>
using namespace std;
string f(int n){
    string res="";
    while(n!=0){
        if(n%2==1){
            res='1'+res;
        }
        else{
            res='0'+res;
        }
        n=n/2;
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    cout<<f(n);
return 0;
}