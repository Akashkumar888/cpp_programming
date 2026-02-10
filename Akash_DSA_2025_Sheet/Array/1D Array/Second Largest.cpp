
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int firstLargest=INT_MIN;
        int secondLargest=INT_MIN;
        for(int &num:arr){
            if(firstLargest<num){
                secondLargest=firstLargest;
                firstLargest=num;
            }
            else if(secondLargest<num && num<firstLargest){
                secondLargest=num;
            }
        }
        return secondLargest==INT_MIN ? -1 : secondLargest;
    }
};



//✔ Works only if array contains non-negative numbers (as per many GFG constraints)
class Solution {
public:
    int getSecondLargest(vector<int> &arr) {
        int firstLargest = -1;
        int secondLargest = -1;

        for (int num : arr) {
            if (num > firstLargest) {
                secondLargest = firstLargest;
                firstLargest = num;
            }
            else if (num < firstLargest && num > secondLargest) {
                secondLargest = num;
            }
        }

        return secondLargest;
    }
};




//✅ If array can contain negative values (MOST CORRECT)
// ✔️ Use long long + flag
class Solution {
public:
    int getSecondLargest(vector<int> &arr) {
        long long firstLargest = LLONG_MIN;
        long long secondLargest = LLONG_MIN;

        for (int num : arr) {
            if (num > firstLargest) {
                secondLargest = firstLargest;
                firstLargest = num;
            }
            else if (num < firstLargest && num > secondLargest) {
                secondLargest = num;
            }
        }

        return (secondLargest == LLONG_MIN) ? -1 : secondLargest;
    }
};
