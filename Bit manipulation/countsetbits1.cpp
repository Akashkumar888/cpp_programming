
#include<bits/stdc++.h>
using namespace std;
int getsetbit(int n){
    int count=0;
    while(n>0){
        if(n&1){
        count++;
        }
        n=n>>1;
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    cout<<getsetbit(n);
    return 0;
}