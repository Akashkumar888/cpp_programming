#include<iostream>
using namespace std;
class Bike{
    public:
int tyresSize;
int engineSize;
Bike(int tyresSize,int engineSize=200){
   this->tyresSize=tyresSize;
   this->engineSize=engineSize;
}
~Bike(){
    cout<<"Distructor is called"<<endl;
}
};
int main(){
Bike tvs(12,800);
Bike honda(13,300);
Bike royalenfield(15,500);
Bike bajaj(17);

bool flag=true;
if(flag){
    Bike bmw(124,789);
    cout<<bmw.tyresSize<<" "<<bmw.engineSize<<endl;
}
// destructor curle braces ke baad call hua
cout<<tvs.tyresSize<<" "<<tvs.engineSize<<endl;
cout<<honda.tyresSize<<" "<<honda.engineSize<<endl;
if(flag){
    Bike bugati(1234,7789);
    cout<<bugati.tyresSize<<" "<<bugati.engineSize<<endl;
}
cout<<royalenfield.tyresSize<<" "<<royalenfield.engineSize<<endl;
cout<<bajaj.tyresSize<<" "<<bajaj.engineSize<<endl;


    return 0;
}