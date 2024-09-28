#include<iostream>
#include<string>
using namespace std;
int main(){
   string s="123456";
   int x=stoi(s);
   cout<<x*2<<endl;

   string s1=to_string(x);
   cout<<s1<<endl;

   string s2="1234567891011121314";
   long long y=stoll(s2);
   cout<<y<<endl;
   string s3="00000000001011121314";
   long long z=stoll(s3);
   cout<<z<<endl;
    return 0;
}