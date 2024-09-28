#include<iostream>
#include<stack>
using namespace std;

bool check(string s){
    stack<char>st;
    int n=s.size();
    if(n%2!=0) return false;
    for(int i=0;i<n;i++){
    if(s[i]=='(') st.push(s[i]);
    else{
      if(st.size()==0) return false;
      else st.pop();
    }
    }
    if(st.size()==0) return true;
    else return false;
}
int main(){
    string s="()()()()";
    cout<<check(s);
    return 0;
}