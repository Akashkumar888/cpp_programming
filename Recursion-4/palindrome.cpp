#include<iostream>
using namespace std;
bool ispalindrome(string s,int i,int j){
    if(i>j) return true;
    if(s[i]!=s[j]) return false;
    return ispalindrome(s,i+1,j-1);
}
int main(){
    string str;
    cin>>str;
    cout<<ispalindrome(str,0,str.size()-1);
    return 0;
}