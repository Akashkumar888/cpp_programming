#include<iostream>
using namespace std;
#include<unordered_set>
void f(string &str,int idx){
if(idx==str.size()){
cout<<str<<endl;
return;
}
unordered_set<char>st;
for(int i=idx;i<str.size();i++){
    if(st.find(str[i])!=st.end()) continue;

    st.insert(str[i]);
    swap(str[i],str[idx]);
    f(str,idx+1);
    swap(str[i],str[idx]);
}
}
int main()
{
    string str="aba";
    f(str,0);
return 0;
}