#include<iostream>
using namespace std;
void fun(int x=7,float y=8.90){ // default value
    cout<<x<<" "<<y;
}
int main(){
    fun(87);
    return 0;
}