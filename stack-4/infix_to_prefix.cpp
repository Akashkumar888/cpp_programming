

#include<iostream>
#include<stack>
using namespace std;
int pr(char ch){
    if(ch=='+' || ch=='-') return 1;
    else if(ch=='*' || ch=='/') return 2;
}
string solve(string val1,string val2,char ch){
    string res="";
    res.push_back(ch);
    res+=val1;
    res+=val2;
    return res;
}
int main(){
    string s="2+(6*4)/8-3";
    int n=s.size();
    stack<string>val;
    stack<char>op;
    for(int i=0;i<n;i++){
        if(s[i]>=48 && s[i]<=57) val.push(to_string(s[i]-'0'));

        else{

        if(op.size()==0) op.push(s[i]);
        else if(s[i]=='(') op.push(s[i]);
        else if(op.top()=='(') op.push(s[i]);

        else if(s[i]==')'){
           while(op.top()!='('){
            char ch=op.top();
            op.pop();
            string val2=val.top();
            val.pop();
            string val1=val.top();
            val.pop();
            string ans=solve(val1,val2,ch);
            val.push(ans);
           }
           op.pop();
        }
        else if(pr(s[i])>pr(op.top())) op.push(s[i]);
        else{
        while(op.size()>0 && pr(s[i])<=pr(op.top())){
            char ch=op.top();
            op.pop();
            string val2=val.top();
            val.pop();
            string val1=val.top();
            val.pop();
            string ans=solve(val1,val2,ch);
            val.push(ans);
        }
        op.push(s[i]);
        }
    }
    }

    while(op.size()>0){
           char ch=op.top();
            op.pop();
            string val2=val.top();
            val.pop();
            string val1=val.top();
            val.pop();
            string ans=solve(val1,val2,ch);
            val.push(ans);
    }
    cout<<val.top()<<endl;
    return 0;
}

