
#include<iostream>
using namespace std;
int minstep(int n){
    if(n==1)return 0;
    if(n==2)return 1;
    if(n==3)return 1;
    int two_2,three_3;
    int ones=minstep(n-1);
    if(n%2==0) two_2=minstep(n/2);
    if(n%3==0) three_3=minstep(n/3);
    int k=min(ones,two_2);
    return 1+min(k,three_3);
}
int main(){
    int n;
    cin>>n;
    cout<<minstep(n)<<endl;
    return 0;
}
