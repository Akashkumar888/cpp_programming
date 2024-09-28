#include<iostream>
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
    int n=str.size();
    for(int i=0;i<n-1;i++){
        bool flag=true;
       for(int j=0;j<n-1-i;j++){
        if(str[j]<str[j+1]){
            int temp=str[j];
            str[j]=str[j+1];
            str[j+1]=temp;
            flag=false;
        }
       }
       if(flag==true) break;
    }
    cout<<str;
    return 0;
}