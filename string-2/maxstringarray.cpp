#include<iostream>
#include<string>
using namespace std;
int main(){
   string s[] = {"0123","0023","456","00182","940","002901"};
   int max=stoi(s[0]);
   string s1=s[0];
   for(int i=1;i<=5;i++){
    int x=stoi(s[i]);
    if(max<x){
     max=x;
     s1=s[i];
    }   
   }
   cout<<max<<endl;
   cout<<s1<<endl;
    return 0;
}