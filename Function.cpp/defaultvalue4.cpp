#include<iostream>
using namespace std;
void fun(int x=7,bool y=true){ // default value
    cout<<x<<" "<<y;
}
int main(){
    fun(false);
    return 0;
}