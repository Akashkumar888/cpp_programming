#include<bits/stdc++.h>
using namespace std;
int main(){
string str;
getline(cin,str);
int n=str.size();
cout<<n<<endl;
if(n%2==0){
    reverse(str.begin()+0,str.begin()+(n/2)); // n/2 me already 1 extra hai the do not add 1 again
    cout<<str;
}
else cout<<"string length are not even:";
    return 0;
}