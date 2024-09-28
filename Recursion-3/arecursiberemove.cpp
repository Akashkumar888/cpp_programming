#include<iostream>
#include<string>
using namespace std;
void removechar(string s,string str){
    if(str.length()==0){
        cout<<s;
        return ;
    }
    char ch=str[0];
    if(ch=='h') removechar(s,str.substr(1));
    else removechar(s+ch,str.substr(1));
}
int main(){
    string str="physics wallah";
    removechar("",str);
    return 0;
}