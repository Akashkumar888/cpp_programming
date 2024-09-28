#include<iostream>
#include<stack>
using namespace std;
int solve(int n1,int n2,char ch){
    if(ch=='+') return n1+n2;
    if(ch=='-') return n1-n2;
    if(ch=='*') return n1*n2;
    if(ch=='/') return n1/n2;
}
int main(){
    string s="79+4*8/3-";
    int n=s.size();
    stack<int>st;
    for(int i=0;i<n;i++){
        if(s[i]>=48 && s[i]<=57) st.push(s[i]-'0');
        else{
            // st.push(s[i]);
            // char ch=st.top();
            // st.pop();
            
            int val2=st.top();
            st.pop();
            int val1=st.top();
            st.pop();
            int ans=solve(val1,val2,s[i]);
            st.push(ans);
        }
    }
    cout<<st.top();
    return 0;
}
