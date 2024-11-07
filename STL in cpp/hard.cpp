#include<bits/stdc++.h>
#include<map>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        string ptr= "codechef";
        map<char,int>m;
        for(int i=0; i<str.length(); i++){
            char s=str[i];
            m[s]++;
        }
        vector<pair<int,char>>v;
        for(auto i:m){
            v.push_back({i.second,i.first});
        }
     sort(v.rbegin(),v.rend());
      vector<char>arr;
        for(int i=0; i<str.length(); i++){
            int m=0;
            int cnt=0;
            for(auto &j:v){
                 cnt++;
                 if(ptr[i]!=j.second && m==0 && j.first>0){
                 arr.push_back(j.second);
                  m=1;
                 
                  j.first--;
                   break;
                 }
                 else if(cnt==v.size() && m==0){
                         arr.push_back(str[i]);
                 }
            }
        }
   int cn=0;
    for(int i=0; i<8; i++){
        if(ptr[i]==arr[i]){
           cn++;
            break;
        }
    }
    if(cn==1){
        cout << -1 << endl;
    }
    else{
        for(auto i:arr){
            cout <<i;
        }
       
    }
       cout << endl;

    }
}