#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    char s[100];
    // getline(cin,s);
    int a[26];
    for(int i=0;i<26;i++){
        s[i]=(char)(97+i);
    }
    for(int i=0;i<26;i++){
        cout<<s[i]<<" ";
    }
    return 0;
}