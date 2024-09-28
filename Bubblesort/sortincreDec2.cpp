#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
    string s="AZYZXBDJKX";
    string str;
    for(int i=0;i<s.length();i++){
        if(s[i]>='X'){
            str.push_back(s[i]);
        }
    }
    cout<<str;
    cout<<endl;
    sort(str.rbegin(),str.rend());
    cout<<str;
    return 0;
}