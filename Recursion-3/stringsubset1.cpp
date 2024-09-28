#include<iostream>
#include<string>
using namespace std;
void printsubset(string s,string str){
    if(str.length()==0){
        cout<<s<<endl;;
        return ;
    }
    char ch=str[0];
    printsubset(s+ch,str.substr(1));
   printsubset(s,str.substr(1));
}
int main(){
    string str="abc";
   printsubset("",str);
    return 0;
}