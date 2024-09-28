#include<bits/stdc++.h>
using namespace std;
string check(string sr){
    stack<char>st;
    int n=sr.size();
    st.push(sr[0]);
    for(int i=1;i<n;i++){
        if(st.top()!=sr[i]) st.push(sr[i]);
    }
    string s="";
    while(st.size()!=0){
        s+=st.top();
        st.pop();
    }
    reverse(s.begin(),s.end());
    return s;
}
int main(){
    string s="aaabbcdddaabffg";
    cout<<s<<endl;
    s=check(s);
    cout<<s<<endl;
    return 0;
}