
#include<iostream>
#include<vector>
using namespace std;
#define ll long long int
vector<ll>dp;
// string decode(string &input){
//     string res="";
//     if(input.size()==1){
//       res+=(char)(64+input[0]-'0');
//     }
//     else{
//         int num=(input[0]-'0')*10+(input[1]-'0');
//         res+=(char)(64+num);
//     }
//     return res;
// }

ll f(string &str,int i){
if(i<=0)return 1;
if(dp[i]!=-1) return dp[i];
ll ans=0;
if(str[i]-'0'> 0){
    ans+=f(str,i-1);
}
if(str[i-1]-'0'>0 && (str[i-1]-'0')*10 + (str[i]-'0') <=26){
    ans+=f(str,i-2);
}
return dp[i]=ans;
}
int main(){
string n;
cin>>n;
while(n[0]!='0'){
dp.clear();
dp.resize(5005,-1);
    cout<<f(n,n.size()-1)<<endl;
    cin>>n;
}
return 0;
}
