#include<iostream>
using namespace std;
int main(){
    char str[]={'a','b','c','d','e','f'};
   for(int i=0;str[i]!='\0';i++){
      cout<<str[i]<<" ";
   }

   cout<<endl;
   cout<<str;
   cout<<endl;
   char str1[]={'a','b','\0','d','e','f'};
   cout<<str1;
    return 0;
}