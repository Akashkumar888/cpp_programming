#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n-1;i++){
        cin>>a[i];
    }
    int x=0;
    for(int i=1;i<=n;i++){
        x=x^i;
    }
    for(int i=0;i<n-1;i++){
        x=x^a[i];
    }
    cout<<x<<endl;
    return 0;
}