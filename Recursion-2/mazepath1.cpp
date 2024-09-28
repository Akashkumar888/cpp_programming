#include<iostream>
using namespace std;
void print(int sr,int sc,int er,int ec,string s){
    if(sr>er || sc>ec) return ;
    if(sr==er && sc==ec){
        cout<<s<<endl;
        return ;
    }
    print(sr,sc+1,er,ec,s+'R');
   print(sr+1,sc,er,ec,s+'D');
    return ;
}
int main(){
   int a,b;
   cin>>a;
   cin>>b;
   print(0,0,a,b,"");
    return 0;
}