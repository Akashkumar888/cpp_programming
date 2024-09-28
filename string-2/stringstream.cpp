#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
int main(){
  string str="raghav is a math teacher";
  stringstream ss(str);
  string temp;
  while(ss>>temp){
    cout<<temp<<endl;
  }
    return 0;
}