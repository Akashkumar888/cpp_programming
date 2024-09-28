#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int main(){
    vector<int>nums={1,2,3,4,5,6};
    int largest=INT_MIN;
    int secondlargest=INT_MIN;

    int smallest=INT_MAX;
    int secondsmallest=INT_MAX;

    for(int i=0;i<nums.size();i++){
    if(largest<nums[i]){
        secondlargest=largest;
        largest=nums[i];
    }
    else{
        secondlargest=max(secondlargest,nums[i]);
    }
    if(smallest>nums[i]){
        secondsmallest=smallest;
        smallest=nums[i];
    }
    else{
        secondsmallest=min(secondsmallest,nums[i]);
    }
    }
    cout<<"largest: "<<largest<<endl;
    cout<<"secondlargest: "<<secondlargest<<endl;
    cout<<"smallest: "<<smallest<<endl;
    cout<<"secondsmallest: "<<secondsmallest<<endl;
    return 0;
}
