#include<iostream>
#include<string>
#include<vector>
using namespace std;
void permutations(vector<string>&finalAns,string ans,string str){
if(str.size()==0){
    finalAns.push_back(ans);
    return;
}
for(int i=0;i<str.size();i++){
    char ch=str[i];
    string left=str.substr(0,i);
    string right=str.substr(i+1);
    permutations(finalAns,ans+ch,left+right);
}
}
int main(){
  string str="abcd";
  vector<string>finalAns;
  permutations(finalAns,"",str);
  for(int i=0;i<finalAns.size();i++){
    cout<<finalAns[i]<<endl;
  }
    return 0;
}