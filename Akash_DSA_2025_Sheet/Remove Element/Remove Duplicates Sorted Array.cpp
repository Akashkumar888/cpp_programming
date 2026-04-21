

class Solution {
  public:
    vector<int> removeDuplicates(vector<int>& arr) {

        set<int> st;

        for(int x : arr) {
            st.insert(x);
        }

        vector<int> result(st.begin(), st.end());
        return result;
    }
};

class Solution {
  public:
    vector<int> removeDuplicates(vector<int>& arr) {

        unordered_set<int> seen;
        vector<int> result;

        for(int i = 0; i < arr.size(); i++) {
            if(seen.find(arr[i]) == seen.end()) {
                result.push_back(arr[i]);
                seen.insert(arr[i]);
            }
        }

        return result;
    }
};

class Solution {
  public:
    vector<int> removeDuplicates(vector<int> &arr) {
        int n = arr.size();
        vector<int> result;

        result.push_back(arr[0]);

        for(int i = 1; i < n; i++) {
            if(arr[i] != arr[i-1]) {
                result.push_back(arr[i]);
            }
        }

        return result;
    }
};