#include<iostream>
using namespace std;
int main(){
char str[100];
cin.get(str,100);
for(int i=0;str[i]!='\0';i++){
    if(i%2==0) str[i]='A';
}
cout<<str;
    return 0;
}