#include<iostream>
using namespace std;
int main(){
    char ch;
    cout<<"Enter character:";
    cin>>ch;
    int ascii=(int)ch;
    if((ascii>=97 && ascii<=122) || (ascii>=65 && ascii<=90)){
        if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' || ch=='a' || ch=='e' ||ch=='i' || ch=='o' || ch=='u'){
        cout<<"The character is vowel"<<endl;
    }
    else{
        cout<<"The character is consonants"<<endl;
    }
    }
    else{
        cout<<"character is not alphabet"<<endl;
    }
    return 0;
}