
class Solution {
  public:
    vector<int> sortBySetBitCount(vector<int>& arr) {
        // code here
        auto lambda=[&](const int &num1,const int &num2){
            return __builtin_popcount(num1) > __builtin_popcount(num2);
        };
        stable_sort(arr.begin(),arr.end(),lambda);//sort according to their position in the original array i.e., a stable sort.
        return arr;
    }
};