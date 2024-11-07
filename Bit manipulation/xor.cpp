#include<bits/stdc++.h>
using  namespace std;
int main(){
    int a,b;
    cin>>a;
    cin>>b;
    cout<<a+b<<endl;
    cout<<((a^b) + 2*(a&b));
    return 0;
}