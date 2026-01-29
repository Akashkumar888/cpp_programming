
class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        int n=arr.size();
        int five=0;
        int ten=0;
        int total=0;
        for(int i=0;i<n;i++){
            if(arr[i]==10 && five>0){
                five--;
            }
            else if(arr[i]==20 && ten>0 && five>0){
                 ten--;
                 five--;
            }
            else if(arr[i]==20 && five>2) {
                five-=3;
            }
            else if((arr[i]==10 && five==0 ) || (arr[i]==20 && (ten==0 || five==0)))return false;
            if(arr[i]==5)five++;
            else if(arr[i]==10)ten++;
        }
        return true;
    }
};

class Solution {
public:
    bool canServe(vector<int> &arr) {
        int five = 0, ten = 0;
        
        for (int &bill : arr) {
            if (bill == 5) {
                five++;
            }
            else if (bill == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            }
            else { // bill == 20
                // prefer giving 10 + 5
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }
                else if (five >= 3) {
                    five -= 3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};


class Solution {
public:
    bool canServe(vector<int>& bills) {
        int five = 0, ten = 0;
        
        for (int b : bills) {
            if (b == 5) {
                five++;
            } else if (b == 10) {
                if (!five) return false;
                five--;
                ten++;
            } else { // b == 20
                if (ten && five) {
                    ten--, five--;
                } 
                else if (five >= 3) {
                    five -= 3;
                } 
                else {
                    return false;
                }
            }
        }
        return true;
    }
};

//leetcode 860. Lemonade Change

// 🧠 Key Strategy for Change Problems
// ✔ Always give the largest possible change
// ✔ Try to preserve smaller bills for future needs
// ✔ For $20, giving $10+$5 is better than 3×$5
// This greedy strategy ensures correctness.