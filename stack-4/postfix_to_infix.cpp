#include<iostream>
#include<stack>
using namespace std;
string solve(string val1,string val2,char ch){
    string res="";
    res+=val1;
    res.push_back(ch);
    res+=val2;
    return res;
}
int main(){
    string s="79+4*8/3-";
    int n=s.size();
    stack<string>st;
    for(int i=0;i<n;i++){
        if(s[i]>=48 && s[i]<=57) st.push(to_string(s[i]-'0'));
        else{
            
            string val2=st.top();
            st.pop();
            string val1=st.top();
            st.pop();
            string ans=solve(val1,val2,s[i]);
            st.push(ans);
            
        }
    }
    cout<<st.top();
    return 0;
}
