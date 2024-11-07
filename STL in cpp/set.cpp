#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int>s;
   s.insert(89);
   s.insert(56);
   s.insert(123);
   s.insert(34);
   s.insert(67);
    // s.insert(67);
   //  s.insert(56);
   cout<<"Size is :"<<s.size()<<endl;
   for(int i:s){
    cout<<i<<"  ";
   }
   cout<<endl;
   s.erase(s.begin());
   for(int i:s){
    cout<<i<<"  ";
   }
    return 0;
}