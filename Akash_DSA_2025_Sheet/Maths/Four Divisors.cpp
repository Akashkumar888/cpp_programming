
class Solution {
public:
    // vector<int> factors(int num) {
    //     vector<int> result;
    //     for (int i = 1; i <= num; i++) {
    //         if (num % i == 0)
    //             result.push_back(i);
    //     }
    //     return result;
    // }
vector<int> factors(int num) {
    vector<int> result;
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            result.push_back(i);
            if (i != num / i)
                result.push_back(num / i);
        }
    }
    return result;
}

    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int& num : nums) {
            vector<int> f = factors(num); // store result ONCE
            if (f.size() == 4) {
                sum += accumulate(f.begin(), f.end(), 0);
            }
        }
        return sum;
    }
};

class Solution {
public:
int factors(int num) {
    int sum=0;
    int cnt=0;
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            cnt++;
            sum+=i;
            if (i != num / i){
                cnt++;
                sum+=(num / i);
            }
        }
    }
    if(cnt!=4)sum=0;
    return sum;
}

    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int& num : nums) {
            sum+=factors(num);
        }
        return sum;
    }
};

class Solution {
public:
    // vector<int> factors(int num) {
    //     vector<int> result;
    //     for (int i = 1; i <= num; i++) {
    //         if (num % i == 0)
    //             result.push_back(i);
    //     }
    //     return result;
    // }
int factors(int num) {
    int sum=0;
    int cnt=0;
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            cnt++;
            sum+=i;
            if (i != num / i){
                cnt++;
                sum+=(num / i);
            }
        }
    }
    return cnt==4 ? sum : 0;
}

    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int& num : nums) {
            sum+=factors(num);
        }
        return sum;
    }
};