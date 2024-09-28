#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
   string s;
   getline(cin,s);
   vector<int>a(26,0);
   for(int i=0;i<s.size();i++){
    char ch=s[i];
    int ascii=(int)ch;
    a[ascii-97]++;
   }
   int max=0;
   for(int i=0;i<26;i++){
     if(a[i]>max) max=a[i];
   }
   for(int i=0;i<26;i++){
     if(a[i]==max){
        cout<<(char)(i+97)<<" "<<max<<endl;
     }
   }
    return 0;
}