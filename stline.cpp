#include<iostream>
using namespace std;
int main(){
    int x1,x2,x3,y1,y2,y3;
    cout<<"Enter the x1 :";
    cin>>x1;
    cout<<"Enter the y1 :";
    cin>>y1;
    cout<<"Enter the x2 :";
    cin>>x2;
    cout<<"Enter the y2 :";
    cin>>y2;
    cout<<"Enter the x3 :";
    cin>>x3;
    cout<<"Enter the y3 :";
    cin>>y3;
    int stline = x1*(y2-y3) + x2*(y3-y1) +x3*(y2-y1);
    cout<<"points on the st line"<<endl;
    cout<<"Value :"<<stline;
    return 0;
}