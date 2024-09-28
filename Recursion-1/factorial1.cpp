#include<iostream>
using namespace std;
void fact(int k){
    int f=1;
    for(int i=1;i<=k;i++){
        f=f*i;
        cout<<"factorial of "<<i<< " is :"<<f<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    fact(n);
    return 0;
}