#include<iostream>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    int n=str.size();
    int count=0;
    for(int i=0;i<n;i++){
        
        if(n==1) break;
        if(n==2 && str[i]!=str[i+1]) {
            count=1;
            break;
        }


        if(i==0){
            if(str[i]!=str[i+1]) count++;
        }
      else if(str[i+1]!=str[i] && str[i]!=str[i-1]){
        count++;
      }
        else if(i==n-1){
          if(str[i]!=str[i-1]) count++;
         }

    }
    cout<<count<<endl;
    return 0;
}