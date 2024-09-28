
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int minimum_product(vector<int>&arr){
    int cn=0;
    int cz=0;
    int cp=0;
    int prod_p=1;
    int prod_n=1;
    int lrneg=INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0) cz++;
        else if(arr[i]>0){
        cp++;
        prod_p*=arr[i];
        } 
        else{
        prod_n*=arr[i];
        cn++;
        lrneg=max(arr[i],lrneg);
        }
    }
    if(cn==0){
        if(cz>0) return 0;
        else{
            auto it=min_element(arr.begin(),arr.end());
            return *it;
        }
    }
    if(cn%2==0){
    return (prod_n/lrneg)*prod_p;
    }
    else if(cn%2!=0){
   return prod_n*prod_p;
    }
}
int main(){
vector<int>arr={-2,-3,1,4,-2,-5};
cout<<minimum_product(arr);
    return 0;
}