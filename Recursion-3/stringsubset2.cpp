#include<iostream>
#include<string>
using namespace std;
void printsubset(string s,string str,int idx){
    if(idx==str.length()){
        cout<<s<<endl;;
        return ;
    }
    char ch=str[idx];
    printsubset(s+ch,str,idx+1);
   printsubset(s,str,idx+1);
}
int main(){
    string str="abc";
   printsubset("",str,0);
    return 0;
}