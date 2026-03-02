
class Solution {
public:
int setBitCount(int num){
    int count=0;
    while(num>0){
        num=num & (num-1);
        count++;
    }
    return count;
}
    vector<int> sortByBits(vector<int>& arr) {
        auto cmp=[&](const int &num1,const int &num2){
            if(setBitCount(num1)==setBitCount(num2))return num1<num2;
            return setBitCount(num1)<setBitCount(num2);
        };

        sort(arr.begin(),arr.end(),cmp);

        return arr;
    }
};



class Solution {
public:
    int setBitCount(int num){
        int count=0;
        while(num>0){
            num = num & (num-1);
            count++;
        }
        return count;
    }

    vector<int> sortByBits(vector<int>& arr) {

        // Store (bitcount, number)
        vector<pair<int,int>> temp;

        for(int num : arr){
            temp.push_back({setBitCount(num), num});
        }

        sort(temp.begin(), temp.end());

        for(int i=0;i<arr.size();i++){
            arr[i] = temp[i].second;
        }

        return arr;
    }
};



vector<int> sortByBits(vector<int>& arr) {

    unordered_map<int,int> mp;

    for(int num : arr){
        mp[num] = setBitCount(num);
    }

    auto cmp = [&](int a, int b){
        if(mp[a] == mp[b])
            return a < b;
        return mp[a] < mp[b];
    };

    sort(arr.begin(), arr.end(), cmp);

    return arr;
}