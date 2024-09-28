#include<bits/stdc++.h>
using namespace std;
void printsubset(string s,string str,vector<string>&v,bool flag){
    if(str.length()==0){
        v.push_back(s);
        return ;
    }
    char ch=str[0];
    if(str.size()==1){
    if(flag==true) printsubset(s+ch,str.substr(1),v,true);
    printsubset(s,str.substr(1),v,true);// taaki dono na chale
    return;
    }
    char dh=str[1];
    if(ch==dh){
    if(flag==true) printsubset(s+ch,str.substr(1),v,true);
    printsubset(s,str.substr(1),v,false);
    }
    else{
        if(flag==true) printsubset(s+ch,str.substr(1),v,true);
    printsubset(s,str.substr(1),v,true);
    }
}
int main(){
    string str="aab";
    vector<string>v;
   printsubset("",str,v,true);
   for(int i=0;i<v.size();i++){
    cout<<v[i]<<endl;
   }
    return 0;
}