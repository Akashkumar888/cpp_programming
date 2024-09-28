#include<iostream>
using namespace std;
int main(){
string str={'a','b','c','d','e'};
cout<<str<<endl;
str.push_back('f');
str.push_back('g');
str.push_back('h');
cout<<str<<endl;
cout<<endl;
string str1="abcd";
cout<<str1<<endl;
str1.push_back('e');
str1.push_back('f');
str1.push_back('g');
cout<<str1<<endl;
str1.pop_back();
cout<<str1<<endl;
    return 0;
}