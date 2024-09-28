#include<iostream>
#include<string>
using namespace std;
int main(){
    string str="abcdef";
    cout<<str<<endl;
    cout<<str.substr(1,4)<<endl;
    for(int i=0;str[i]!='\0';i++){
    cout<<str.substr(i) <<" ";
    }
    return 0;
}