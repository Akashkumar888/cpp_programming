#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    pair<int,int> mostFrequent(vector<int> &arr) {

        unordered_map<int,int> mp;

        // count frequencies
        for(int &num : arr){
            mp[num]++;
        }

        int maxFreq = 0;
        int number = 0;

        for(auto &it : mp){

            // larger frequency
            if(it.second > maxFreq){
                maxFreq = it.second;
                number = it.first;
            }

            // tie -> smaller number
            else if(it.second == maxFreq && it.first < number){
                number = it.first;
            }
        }

        return {number, maxFreq};
    }
};


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    pair<int,int> mostFrequent(vector<int> &arr) {

        vector<int>mp(1e5+1,0);

        // count frequencies
        for(int &num : arr){
            mp[num]++;
        }

        int maxFreq = 0;
        int number = 0;

        for(int i=1;i<=1e5+1;i++){

            // larger frequency
            if(mp[i] > maxFreq){
                maxFreq = mp[i];
                number = i;
            }

            // tie -> smaller number
            else if(mp[i] == maxFreq && i < number){
                number = i;
            }
        }

        return {number, maxFreq};
    }
};
