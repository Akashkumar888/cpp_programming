#include<iostream>
using namespace std;
int main(){
    char ch;
    cout<<"Enter character:";
    cin>>ch;
    int ascii=(int)ch;
    if((ascii>=97 && ascii<=122) || (ascii>=65 && ascii<=90)){
        cout<<"The character is alphabet"<<endl;
    }
    else{
        cout<<"The character is not alphabet"<<endl;
    }
    return 0;
}