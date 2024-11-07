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
   set<int> ::iterator it=s.begin();
   it++;
    // it++;
   s.erase(it);
   for(int i:s){
    cout<<i<<"  ";
   }
   cout<<endl;
   cout<<"67 is present or not : "<<s.count(67)<<endl;
   set<int>::iterator itr=s.find(67);
   for(auto it=itr;it!=s.end();it++){
    cout<<*it<<" ";
   }
   cout<<endl;
    return 0;
}