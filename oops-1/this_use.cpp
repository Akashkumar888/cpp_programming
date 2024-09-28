#include<iostream>
using namespace std;
class player{
private: 
int score;
int health;
int age;
bool alive;
public:
void setscore(int score){
    this->score=score; // this denoted only inside the variable scope
}
void sethealth(int health){
    this->health=health;
}
void setage(int age){
    this->age=age;
}
void setalive(bool alive){
    this->alive=alive;
}
int getscore(){
    return score;
}
int gethealth(){
    return health;
}
int getage(){
    return age;
}
int getalive(){
    return alive;
}
};
int addscore(player a,player b){
    return a.getscore()+b.getscore();
}
int main(){
 player akash,surya;
 akash.setscore(10);
 akash.sethealth(200);
 akash.setage(20);
 akash.setalive(true);

 cout<<akash.getscore()<<" "<<akash.gethealth()<<" "<<akash.getage()<<" "<<akash.getalive()<<endl;
 surya.setscore(20);
 surya.sethealth(245);
 surya.setage(60);
 surya.setalive(true);
 cout<<surya.getscore()<<" "<<surya.gethealth()<<" "<<surya.getage()<<" "<<surya.getalive()<<endl;
cout<<addscore(akash,surya);
    return 0;
}