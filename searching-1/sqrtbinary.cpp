#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int i=0;
    int j=n;
    bool flag=false;
    while(i<=j){
        long long mid=i+(j-i)/2;
        if(mid*mid==n){
            flag=true;
            cout<<mid;
            break;
        }
        else if(mid*mid<n) i=mid+1;
        else if(mid*mid>n) j=mid-1;
    }
    if(flag==false) cout<<j;
    return 0;
}