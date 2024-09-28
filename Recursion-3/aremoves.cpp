#include<iostream>
#include<string>
using namespace std;
void removechar(string s,string str,int idx){
    if(idx==str.length()){
        cout<<s;
        return ;
    }
    char ch=str[idx];
    if(ch=='a') removechar(s,str,idx+1);
    else removechar(s+ch,str,idx+1);
}
int main(){
    string str="physics wallah";
    removechar("",str,0);
    return 0;
}