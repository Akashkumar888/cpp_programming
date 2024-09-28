#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    sort(s.begin(),s.end()); // sort according to ascii value
    cout<<s<<endl;
    return 0;
}