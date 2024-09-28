#include<iostream>
using namespace std;
int main(){
    int test=0; // test=0 meaning false and ascii value
    cout<<"First character "<<'1'<<endl;
    cout<<"Seconf character "<<(test ? 3: '1')<<endl;
    return 0;
}