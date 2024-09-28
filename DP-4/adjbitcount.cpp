
#include<iostream>
#include<vector>
using namespace std;
int main(){
   string s="011101101";
   int sum=0;
   for(int i=0;i<s.size()-1;i++){
    sum+=((s[i]-'0')*(s[i+1]-'0'));
   }
   cout<<sum;
    return 0;
}