#include<iostream>
#include<cmath>
using namespace std;
class Solution {
public:
bool isperfectsquare(int n){
    int root=sqrt(n);
    if(root*root==n) return true;
    else return false;
}
    bool judgeSquareSum(int c) {
        int x=0;
        int y=c;
        while(x<=y){
            if(isperfectsquare(x) && isperfectsquare(y)){
                return true;
                x++;
                y--;
            }
        }
        return false;
    }
};