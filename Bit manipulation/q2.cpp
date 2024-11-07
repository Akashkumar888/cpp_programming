#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i;
    cin>>n>>i;
    if(  n & (1<<(i-1))  ) cout<<"Yes"; // left shift 
    else cout<<"No";
    return 0;
}