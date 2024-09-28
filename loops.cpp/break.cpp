#include<iostream>
using namespace std;
int main(){
    int x=4;
    int y=0;
    int z;
    while(x>=0){
          if(x==y)
            break;  // break ka meaning pure loop se bahar ho jao jisme ho
          
          else
            cout<<x<<" "<<y<<endl;
          x--;
          y++;
    }
    return 0;
}