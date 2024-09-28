#include<iostream>
#include<string>
#include<vector>
using namespace std;
void printsubset(string s,string str,int idx,vector<string>&v){
    if(idx==str.length()){
        v.push_back(s);
        return ;
    }
    char ch=str[idx];
    printsubset(s+ch,str,idx+1,v);
    printsubset(s,str,idx+1,v);
}
int main(){
    string str="abc";
    vector<string>v;
   printsubset("",str,0,v);
   for(string ele :v){
    cout<<ele<<endl;
   }
    return 0;
}