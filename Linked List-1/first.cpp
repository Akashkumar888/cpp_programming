#include<iostream>
using namespace std;
class Student{
public:
string name;
int rno;
float marks;
Student (string name,int rno,float marks){
    this->name=name;
    this->rno=rno;
    this->marks=marks;
}
};
void change(Student  s){
    s.name="Harsh";
}
int main(){
 Student s("Raghav",216,98.8);
 cout<<s.name<<endl;
 change(s);
 cout<<s.name<<endl;
    return 0;
}