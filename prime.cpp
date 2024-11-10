#include<iostream>
using namespace std;
bool prime(int n){
  if(n==1)return false;
  bool flag=true;
  for(int i=2;i<n;i++){
    if(n%i==0)flag=false;
  }
  return flag;
}
int main()
{
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    if(prime(i))cout<<i<<" ";
  }
return 0;
}
