#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    string s1;
    getline(cin,s1);
    sort(s.begin(),s.end()); // sort according to ascii value
    sort(s1.begin(),s1.end()); // sort according to ascii value
    if(s==s1) cout<<"Anagram";
    else cout<<"Not anagram";
    return 0;
}