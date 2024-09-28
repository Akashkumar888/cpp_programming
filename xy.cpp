#include<iostream>
using namespace std;
int main(){
    int x,y;
    cout<<"Enter the x :";
    cin>>x;
    cout<<"Enter the y :";
    cin>>y;
    if(x>0 && y>0){
        cout<<"points lies in the 1st quadrant";
    }
    else if(x<0 && y>0){
        cout<<"points lies in the 2nd quadrant";
    }
    else if(x<0 && y<0){
        cout<<"points lies in the 3rd quadrant";
    }
    else if(x>0 && y<0){
        cout<<"points lies in the 4th quadrant";
    }
     else if(x>0){
        cout<<"points lie on x line";
     }
     else if(y>0){
        cout<<"points lie on y line";
     }
    return 0;
}