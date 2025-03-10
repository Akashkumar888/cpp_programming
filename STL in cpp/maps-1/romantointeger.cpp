#include<iostream>
#include<map>
using namespace std;
int roman_to_int(string s){
    map<char,int>m={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int total=0;
     for(int i=0;i<s.size();i++){
        if(m[s[i]]>=m[s[i+1]]) total=total+m[s[i]];
        else total=total-m[s[i]];
     }
     return total;
}
int main(){
    string s;
    cin>>s;
    cout<<roman_to_int(s);
    return 0;
}