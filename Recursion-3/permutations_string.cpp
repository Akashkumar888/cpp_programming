#include<iostream>
#include<string>
#include<vector>
using namespace std;
void permutations(string ans,string str){
if(str.size()==0){
    cout<<ans<<endl;
    return;
}
for(int i=0;i<str.size();i++){
    char ch=str[i];
    string left=str.substr(0,i);
    string right=str.substr(i+1);
    permutations(ans+ch,left+right);
}
}
int main(){
  string str="abcd";
  permutations("",str);
    return 0;
}