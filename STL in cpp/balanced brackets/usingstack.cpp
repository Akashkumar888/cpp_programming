#include<bits/stdc++.h>
using namespace std;
unordered_map<char,int>symbols={ {'(',-1},{'{',-2},{'[',-3},{')',1},{'}',2},{']',3} };
string isbalanced(string s){
stack<char>c;
for(char i:s){
    if(symbols[i]<0){
        c.push(i);
    }
    else{
  if(c.empty()) return "NO";
  char top=c.top();
   c.pop();
   if(symbols[top]+symbols[i]!=0) return "NO";
    }
}
if(c.empty()) return "YES";
else return "NO";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<isbalanced(s)<<endl;
    }
    return 0;
}