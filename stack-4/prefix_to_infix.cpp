
#include<iostream>
#include<stack>
using namespace std;
string solve(string n1,string n2,char ch){
    string s="";
    s+=n1;
    s.push_back(ch);
    s+=n2;
    return s;
}
int main(){
    stack<string>st;
    string s="-/*+79483";
    int n=s.size();
    for(int i=n-1;i>=0;i--){
        if(s[i]>=48 &&s[i]<=57) st.push(to_string(s[i]-'0'));
        else{
            string val1=st.top();
            st.pop();
            string val2=st.top();
            st.pop();
            string ans=solve(val1,val2,s[i]);
            st.push(ans);
        }
    }
    cout<<st.top();
    return 0;
}
