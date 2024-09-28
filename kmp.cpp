#include<iostream>
using namespace std;
int main()
{
    string s="abcdabcd";
    string pre="",suf="";
    int count=0;
    for(int i=0;i<s.size()-1;i++){
        pre=pre+s[i];
        suf = s[s.size() - 1 - i] + suf; 
        if(pre==suf){
            count=max(i+1,count);
        }
    }
    cout<<count<<endl;
return 0;
}