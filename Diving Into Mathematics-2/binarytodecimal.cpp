#include<iostream>
using namespace std;
int binarytodecimal(string &str){
    int n=str.size();
    int result=0;
    for(int i=n-1;i>=0;i--){
        char ch=str[i];
        int num=ch-'0';
        result+=num*(1<<(n-i-1));
    }
    return result;
}
int main(){
   string str;
   cin>>str;
   cout<<binarytodecimal(str);
    return 0;
}