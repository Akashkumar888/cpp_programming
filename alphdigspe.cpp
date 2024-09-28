#include<iostream>
using namespace std;
int main(){
    char ch;
    cout<<"Enter character :";
    cin>>ch;
    if(((int)ch>=65 && (int)ch<=90) || ((int)ch>=97) && (int)ch<=122){
        cout<<"Alphabet";
    }
    else if(((int)ch>=48 && (int)ch<=57)){
        cout<<"Digit";
    }
    else{
        cout<<"Special character";
    }
    return 0;
}