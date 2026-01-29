
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        // diff array technique
        vector<int>diff(2051,0);
        for(auto &it:logs){
            int l=it[0];// start date
            int r=it[1]-1;// end date
            diff[l]+=1;
            diff[r+1]-=1; 
        }
        int cumSum=0;
        int maxSum=0;
        int year=0;
        for(int i=0;i<2051;i++){
            cumSum+=diff[i];
            diff[i]=cumSum;
            if(cumSum>maxSum){
                maxSum=cumSum;
                year=i;
            }
        }
        return year;
    }
};


class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        // diff array technique
        vector<int>diff(2051,0);
        for(auto &it:logs){
            int l=it[0];// start date
            int r=it[1]-1;// end date
            diff[l]+=1;
            diff[r+1]-=1; 
        }
        int cumSum=0;
        int maxSum=0;
        int minYear=2050;
        for(int i=1950;i<2051;i++){
            cumSum+=diff[i];
            diff[i]=cumSum;
            if(cumSum>maxSum){
                maxSum=cumSum;
                minYear=i;
            }
        }
        return minYear;
    }
};