#include<iostream>
using namespace std;
void fun(int x=7,int y=8){ // default value
    cout<<x<<" "<<y;
}
int main(){
    fun(4,3);
    return 0;
}