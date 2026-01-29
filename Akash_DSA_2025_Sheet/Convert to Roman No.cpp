
class Solution {
  public:
    string convertToRoman(int n) {
        // code here
        vector<pair<string,int>>v={
            {"M",1000},{"CM",900},{"D",500},{"CD",400},
            {"C",100},{"XC",90},{"L",50},{"XL",40},
            {"X",10},{"IX",9},{"V",5},{"IV",4},
            {"I",1}
        };
        int num=n;
        string str="";
        for(int i=0;i<13;i++){
            int times=num/v[i].second;
            while(times--){
                str+=v[i].first;
            }
            num=num - (num/v[i].second) * v[i].second;
        }
        return str;  
    }
};

// Time Complexity:
// The v vector has a constant size of 13, so the loop runs 13 times.
// Inside the loop:
// num / v[i].second gives how many times the Roman symbol fits — at most 3–4 iterations per Roman character (e.g., III, XXX, etc.).
// So, total number of iterations is bounded and does not scale with the input value.
// Hence, Time: O(1) (constant time)

// Space Complexity:
// Result string can be at most length 15 (e.g., for 3888 → MMMDCCCLXXXVIII).
// Vector v is constant size.
// So, Space: O(1)

