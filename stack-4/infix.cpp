
#include<iostream>
#include<stack>
using namespace std;
int pr(char ch){
  if(ch=='+' || ch=='-') return 1;
  return 2;
}
int solve(int n1,int n2,char ch){
    if(ch=='+') return n1+n2;
    else if(ch=='-') return n1-n2;
    else if(ch=='*') return n1*n2;
    else if(ch=='/') return n1/n2;
}
int main(){
    string s="2+6*4/8-3";
    stack<int>val;
    stack<char>op;
    int n=s.size();
    for(int i=0;i<n;i++){

        //  int ascii=(int)s[i]; // automatic ascii value in cpp
        // if(ascii>=48 && ascii<=57){
        //     val.push(ascii-48);
        // }
        
        if(s[i]>=48 && s[i]<=57){
            val.push(s[i]-'0');
        }
        else{
            if(op.size()==0) op.push(s[i]);
            else if(pr(s[i])>pr(op.top())){
                op.push(s[i]);
            }
            else{
                while(op.size()>0 && pr(s[i])<=pr(op.top())){
                char ch=op.top();
                op.pop();
                int val2=val.top();
                val.pop();
                int val1=val.top();
                val.pop();
                int ans=solve(val1,val2,ch);
                val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }
    while(op.size()>0){
                char ch=op.top();
                op.pop();
                int val2=val.top();
                val.pop();
                int val1=val.top();
                val.pop();
                int ans=solve(val1,val2,ch);
                val.push(ans);
    }
    cout<<val.top();
    return 0;
}
