#include<iostream>
using namespace std;
int main(){
    string haystack="abacdabad";
    string needle="abad";
    int n=haystack.size();
    int m=needle.size();
    for(int i=0;i<=n-m;i++){
        int first=i,second=0;
        while(second<m){
        if(haystack[first]!=needle[second]){
            break;
        }
        else{
            first++,second++;
        }
        }
        if(second==m){
            cout<<n-m<<endl;
        }
    }
       cout<<-1<<endl;
    return 0;
}