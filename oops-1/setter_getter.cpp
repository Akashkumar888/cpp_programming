#include<iostream>
using namespace std;
class students{
private:  // data private and function  public 
int score;
int health;
public:
void setscore(int s){
    score=s;
}
void sethealth(int h){
    health=h;
}
int getscore(){
    return score;
}
int gethealth(){
    return health;
}
};
int main(){
 students akash;
 akash.setscore(10);
 cout<<akash.getscore()<<endl;
 akash.sethealth(200);
 cout<<akash.gethealth();
    return 0;
}